// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-11
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += val;
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += node_val[i];
		return ret;
	}
};

struct query {
	int l, r, id;
};

void solve(vector<cat> A, vector<query> qs, vector<cat> & ans, vector<cat> & cur) {
	int N = A.size();
	vector< pair<cat,int> > nxt(N, {0, N});
	stack< pair<cat,int> > st;
	for(int i = N-1; i >= 0; i--) {
		while(!st.empty() && st.top().ff >= A[i]) st.pop();
		if(!st.empty()) nxt[i] = st.top();
		st.push({A[i], i});
	}
	vector< vector<cat> > mi(20, vector<cat>(N, OVER9000));
	for(int i = 0; i < N; i++) mi[0][i] = A[i];
	for(int k = 1; k < 20; k++) for(int i = 0; i <= N-(1<<k); i++)
		mi[k][i] = min(mi[k-1][i], mi[k-1][i+(1<<(k-1))]);
	vector< vector< pair<cat,int> > > nxtp(20, vector< pair<cat,int> >(N, {0, N}));
	for(int i = 0; i < N; i++) if(nxt[i].ss < N) nxtp[0][i] = {(nxt[i].ss-i)*A[i], nxt[i].ss};
	for(int k = 1; k < 20; k++)
		for(int i = 0; i < N; i++) if(nxtp[k-1][i].ss < N && nxtp[k-1][nxtp[k-1][i].ss].ss < N)
			nxtp[k][i] = {nxtp[k-1][i].ff + nxtp[k-1][nxtp[k-1][i].ss].ff, nxtp[k-1][nxtp[k-1][i].ss].ss};
	for(auto qu : qs) {
		for(int k = 19; k >= 0; k--) if(qu.l+(1<<k) <= qu.r && mi[k][qu.l] >= cur[qu.id]) {
			ans[qu.id] += (1<<k) * cur[qu.id];
			qu.l += 1<<k;
		}
		for(int k = 19; k >= 0; k--) while(nxtp[k][qu.l].ss < qu.r) {
			ans[qu.id] += nxtp[k][qu.l].ff;
			qu.l = nxtp[k][qu.l].ss;
		}
		if(qu.l < qu.r) ans[qu.id] += A[qu.l] * (qu.r-qu.l);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, Q, K;
	cin >> N >> Q >> K;
	vector<cat> A(N+2*K, OVER9000);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<int> L(Q), R(Q);
	vector< vector<int> > id_by_rem(K);
	vector<cat> ans(Q), cur(Q);
	for(int i = 0; i < Q; i++) {
		cin >> L[i] >> R[i];
		ans[i] = cur[i] = A[L[i]-1];
		R[i] = L[i]+(R[i]-L[i])/K*K;
		id_by_rem[L[i]%K].push_back(i);
	}
	multiset<int> seg_val;
	for(int i = 0; i < K; i++) seg_val.insert(A[i]);
	vector<cat> B(N+K);
	for(int i = 0; i < N+K; i++) {
		B[i] = *(seg_val.begin());
		seg_val.erase(seg_val.find(A[i]));
		seg_val.insert(A[i+K]);
	}
	for(int r = 0; r < K; r++) {
		vector<cat> Ar;
		vector<query> Qr;
		for(int i = r; i < N+K; i += K) Ar.push_back(B[i]);
		for(auto id : id_by_rem[r]) Qr.push_back({.l = L[id]/K, .r = R[id]/K, .id = id});
		solve(Ar, Qr, ans, cur);
	}
	for(int i = 0; i < Q; i++) cout << ans[i] << "\n";
}

// look at my code
// my code is amazing