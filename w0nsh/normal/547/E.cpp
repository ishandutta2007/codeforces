#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<
T,
null_type,
std::less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;

//X.find_by_order(k); - zwraca iterator na k-ty element (numeracja od zerowego)
//X.order_of_key(k); - zwraca liczb elementw ostro mniejszych ni k

// https://doi.org/10.1145/1217856.1217858
inline bool leq(int a1, int a2, int b1, int b2){
	return a1 < b1 || (a1 == b1 && a2 <= b2);
}
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3){
	return a1 < b1 || (a1 == b1 && leq(a2, a3, b2, b3));
}
void radix(int *a, int *b, int *r, int n, int K){
	int *c = new int[K+1];
	for(int i = 0; i <= K; ++i) c[i] = 0;
	for(int i = 0; i < n; ++i) c[r[a[i]]]++;
	for(int i = 0, sum = 0, t = 0; i <= K; ++i) t = c[i], c[i] = sum, sum += t;
	for(int i = 0; i < n; ++i) b[c[r[a[i]]]++] = a[i];
	delete [] c;
}
// A = {1..K}
// T[0..n-1] - word
// T[n] = T[n+1] = T[n+2] = 0
// SA[0..n-1] - output
void suffix_array(int *T, int *SA, int n, int K){
	if(n == 1){
		SA[0] = 0;
		return;
	}
	int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02=n0+n2;
	int *R = new int[n02+3];
	int *SA12 = new int[n02+3];
	int *R0 = new int[n02];
	int *SA0 = new int[n02];
	for(int i = 0; i < 3; ++i) R[n02+i] = SA12[n02+i] = 0;
	for(int i = 0, j = 0; i < n+n0-n1; ++i) if(i%3) R[j++] = i;
	radix(R, SA12, T+2, n02, K);
	radix(SA12, R, T+1, n02, K);
	radix(R, SA12, T, n02, K);
	int name = 0, c0 = -1, c1 = -1, c2 = -1;
	for(int i = 0; i < n02; ++i){
		if(T[SA12[i]] != c0 || T[SA12[i]+1] != c1 || T[SA12[i]+2] != c2)
			name++, c0 = T[SA12[i]], c1 = T[SA12[i]+1], c2 = T[SA12[i]+2];
		if(SA12[i]%3 == 1) R[SA12[i]/3] = name;
		else R[SA12[i]/3+n0] = name;
	}
	if(name < n02){
		suffix_array(R, SA12, n02, name);
		for(int i = 0; i < n02; ++i) R[SA12[i]] = i+1;
	}else for(int i = 0; i < n02; ++i) SA12[R[i]-1] = i;
	for(int i = 0, j = 0; i < n02; ++i) if(SA12[i] < n0) R0[j++] = 3*SA12[i];
	radix(R0, SA0, T, n0, K);
	for(int p = 0, t = n0-n1, k = 0; k < n; ++k){
		#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
		int i = GetI();
		int j = SA0[p];
		if(SA12[t] < n0 ?
			leq(T[i], R[SA12[t]+n0], T[j], R[j/3]) :
			leq(T[i], T[i+1], R[SA12[t]-n0+1], T[j], T[j+1], R[j/3+n0])){
			SA[k] = i, t++;
			if(t == n02) for(k++; p < n0; p++, k++) SA[k] = SA0[p];
		}else{
			SA[k] = j; p++;
			if(p == n0) for(k++; t < n02; t++, k++) SA[k] = GetI();
		}
	}
	delete[] R; delete[] SA12; delete[] SA0; delete[] R0;
}

// lcp[0..n-2] - output
void kasai(int *T, int *sa, int *lcp, int n){
	int k = 0;
	int *rank = new int[n];
	for(int i = 0; i < n; ++i) rank[sa[i]] = i;
	for(int i = 0; i < n; ++i, k?k--:0){
		if(rank[i] == n-1){
			k = 0; continue;
		}
		int j = sa[rank[i]+1];
		while(i+k<n && j+k<n && T[i+k] == T[j+k]) k++;
		lcp[rank[i]] = k;
	}
	delete[] rank;
}

// A = {1..K}
// T[0..n-1] - word
// T[n] = T[n+1] = T[n+2] = 0
// SA[0..n-1] - output
// void suffix_array(int *T, int *SA, int n, int K)


const int M = 400010;
int T[M], sa[M], lcp[M], rank[M];
/*
const int MOD = 1000000007;
const int P = 5315;
int hash[M], pw[M];

bool same(int a, int b, int l){
	a++;b++;
	int h1 = (hash[a+l-1]-hash[a]*pw[l])%MOD;
	if(h1 < 0) h1 += MOD;
	int h2 = (hash[b+l-1]-hash[b]*pw[l])%MOD;
	if(h2 < 0) h2 += MOD;
	return h1 == h2;
}*/

const int INF = 1000000666;
struct Tree{
	int BOTTOM;
	VI t;
	int szzz;
	void build(VI A){
		szzz = SZ(A);
		BOTTOM = 1;
		while(BOTTOM < SZ(A)) BOTTOM *= 2;
		t.resize(BOTTOM*2, INF);
		FOR(i, SZ(A)) t[i+BOTTOM] = A[i];
		for(int i = BOTTOM-1; i >= 1; --i) t[i] = std::min(t[i<<1], t[(i<<1)+1]);
	}

	int query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		int ret = INF;
		while(a < b){
			if(a&1) ret = std::min(ret, t[a++]);
			if(b&1) ret = std::min(ret, t[--b]);
			a>>=1;b>>=1;
		}
		return ret;
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, q;
	std::cin >> n >> q;
	std::vector<VI> A(n);

	VI slo;
	VI pss(n);
	FOR(i, n){
		std::string s;
		std::cin >> s;
		pss[i] = SZ(slo);
		TRAV(c, s) A[i].push_back(SZ(slo)), slo.push_back(c-'a'+2);
		slo.push_back(1);
	}
/*
	hash[0] = 0;
	pw[0] = 1;
	REP(i, 1, M) pw[i] = (1ll*pw[i-1]*P)%MOD;
	FOR(i, SZ(slo)){
		hash[i+1] = (1ll*hash[i]*P + slo[i])%MOD;
	}
*/
	FOR(i, SZ(slo)) T[i] = slo[i];
	REP(i, SZ(slo), SZ(slo)+3) T[i] = 0;

	suffix_array(T, sa, SZ(slo), 50);
	kasai(T, sa, lcp, SZ(slo));

	FOR(i, SZ(slo)) rank[sa[i]] = i;
	/*FOR(i, SZ(slo)) std::cout << slo[i] << " ";
	std::cout << "\n";
	FOR(i, SZ(slo)) std::cout << rank[i] << " ";
	std::cout << "\n";*/

	Tree tree;
	VI hehe(SZ(slo)-1);
	FOR(i, SZ(slo)-1) hehe[i] = lcp[i];
	tree.build(hehe);

	VI ans(q);
	std::vector<std::vector<PII> > events(n);
	std::vector<PII> prze(q);

/*
	FOR(i, SZ(slo)) std::cerr << (slo[i] == 1 ? "|" : std::to_string(slo[i])) << " ";
	std::cerr << std::endl;
*/
	FOR(i, q){
		int l, r, k;
		std::cin >> l >> r >> k;
		l--;r--;k--;
		int p = rank[pss[k]];


		int left = 0;
		int right = p;
		while(left < right){
			int mid = (left+right)/2;
			if(tree.query(mid, p-1) < SZ(A[k])) left = mid+1;
			else right = mid;
		}

		int L = left;

		left = p;
		right = SZ(slo);
		while(left < right){
			int mid = (left+right)/2;
			if(tree.query(p, mid-1) >= SZ(A[k])) left = mid+1;
			else right = mid;
		}
		left--;

		int R = left;

		prze[i] = MP(L, R);

		if(l > 0) events[l-1].push_back(MP(i, -1));
		events[r].push_back(MP(i, 1));
	}

	ordered_set<int> set;

	auto ask = [&](int a, int b){
		return set.order_of_key(b+1) - set.order_of_key(a);
	};

	FOR(i, n){
		TRAV(j, A[i]) set.insert(rank[j]);
		TRAV(ev, events[i]){
			int a = prze[ev.X].X;
			int b = prze[ev.X].Y;
			ans[ev.X] += ev.Y*ask(a, b);
		}
	}

	FOR(i, q) std::cout << ans[i] << "\n";

	return 0;
}