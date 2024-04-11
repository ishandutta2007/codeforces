#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned int ull;
typedef long double dbl;
typedef pair <int, int> pii;

inline bool cmp2(int a1, int a2, int b1, int b2){
	if(a1 == b1)
		return a2 < b2;
	else
		return a1 < b1;
}

inline bool cmp3(int a1, int a2, int a3, int b1, int b2, int b3){
	if(a1 == b1)
		return cmp2(a2, a3, b2, b3);
	else
		return a1 < b1;
}

void radix_pass(int *src, int *dest, int *s, int n, int alpha){
	int *cnt = new int[alpha + 1];
	std::fill(cnt, cnt + alpha + 1, 0);
	for(int i = 0; i < n; i++){
		++cnt[s[src[i]]];
	}
	int sum = 0;
	for(int i = 0; i < alpha + 1; i++){
		int t = cnt[i];
		cnt[i] = sum;
		sum += t;
	}
	for(int i = 0; i < n; i++){
		dest[cnt[s[src[i]]]++] = src[i];
	}
	delete[] cnt;
}

void build_array(int *s, int *ends, int alpha, int *sa){
	int n = ends - s;
	if(n == 1){
		*sa = 0;
		return;
	}
	int n0 = (n + 2)/3, n1 = (n + 1)/3, n2 = n/3;
	int n02 = n0 + n2;
	int *s0 = new int[n0], *sa0 = new int[n0];
	int *s12 = new int[n02 + 3], *sa12 = new int[n02 + 3];
	s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0;
	sa12[n02] = sa12[n02 + 1] = sa12[n02 + 2] = 0;
	for(int i = 0, j = 0; i < n + (n0 - n1); i++){
		if(i%3)
			s12[j++] = i;
	}
	radix_pass(s12, sa12, s + 2, n02, alpha);
	radix_pass(sa12, s12, s + 1, n02, alpha);
	radix_pass(s12, sa12, s, n02, alpha);
	int tot = 0, c0 = -1, c1 = -1, c2 = -1;
	for(int i = 0; i < n02; i++){
		if(s[sa12[i]] != c0 || s[sa12[i] + 1] != c1 || s[sa12[i] + 2] != c2){
			++tot;
			c0 = s[sa12[i]];
			c1 = s[sa12[i] + 1];
			c2 = s[sa12[i] + 2];
		}
		if(sa12[i]%3 == 1)s12[sa12[i]/3] = tot;
		else s12[sa12[i]/3 + n0] = tot;
	}
	if(tot != n02){
		build_array(s12, s12 + n02, tot, sa12);
		for(int i = 0; i < n02; i++)
			s12[sa12[i]] = i + 1;
	}else{
		for(int i = 0; i < n02; i++)
			sa12[s12[i] - 1] = i;
	}
	for(int i = 0, j = 0; i < n02; i++){
		if(sa12[i] < n0)s0[j++] = sa12[i] * 3;
	}
	radix_pass(s0, sa0, s, n0, alpha);
	int l = 0, r = n0 - n1, ptr = 0;
	for(; ptr < n; ptr++){
		int i = sa12[r] < n0 ? sa12[r] * 3 + 1 : (sa12[r] - n0) * 3 + 2;
		int j = sa0[l];
		bool le = sa12[r] < n0 ? cmp2(s[i], s12[sa12[r] + n0], s[j], s12[j/3]) : cmp3(s[i], s[i + 1], s12[sa12[r] - n0 + 1], s[j], s[j + 1], s12[j/3 + n0]);
		if(le){
			sa[ptr] = i;
			++r;
			if(r == n02){
				for(; l < n0; l++){sa[++ptr] = sa0[l];}
				break;
			}
		}
		else{
			sa[ptr] = j;
			++l;
			if(l == n0){
				for(; r < n02; r++){sa[++ptr] = sa12[r] < n0 ? sa12[r] * 3 + 1 : (sa12[r] - n0) * 3 + 2;}
				break;
			}
		}
	}
	delete[] s0; delete[] sa0;
	delete[] s12; delete[] sa12;
}

template<class RandomAccessIterator>
int* suffix_array(const RandomAccessIterator & from, const RandomAccessIterator & to){
	int n = to - from;
	int *s = new int[n + 3];
	int *ptr = s;
	int alpha = 0;
	bool has0 = false;
	for(auto it = from; it != to; it++){
		*ptr = *it;
		if(!(*ptr))has0 = true;
		alpha = max(alpha, *ptr);
		++ptr;
	}
	*ptr = *(ptr + 1) = *(ptr + 2) = 0;
	if(has0){
		++alpha;
		for(ptr = s; ptr < s + n; ptr++){
			++(*ptr);
		}
	}
	int * sa = new int[n];
	build_array(s, s + n, alpha, sa);
	delete[] s;
	return sa;
}

template<class RandomAccessIterator>
int* calc_lcp(int n, const RandomAccessIterator & from, const int* sa){
	int * lcp = new int[n];
	int * pos = new int[n];
	for(int i = 0; i < n; i++)
		pos[sa[i]] = i;
	int k = 0;
	for(int i = 0; i < n; i++){
		if(k > 0)
			--k;
		if(pos[i] == n - 1){
			lcp[n - 1] = -1;
			k = 0;
		}
		else{
			int j = sa[pos[i] + 1];
			while(std::max(i + k, j + k) < n && *(from + i + k) == *(from + j + k))
				++k;
			lcp[pos[i]] = k;
		}
	}
	delete[] pos;
	return lcp;
}

const int N = (int)1e6 + 6;
const int LG = 21;

string s, t;
int ns, nt;
int * sa, * lcp;
int z[N];
int st[LG][N];
int spos[N];
int lg[N];

void calcz(){
	int n = t.length();
	z[0] = 0;
	int l = 0, r = 0;
	F(i, 1, n){
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && t[z[i]] == t[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	z[0] = n;
}

void build_st(){
	F(i, 0, nt)st[0][i] = lcp[i]; 
	F(j, 1, LG){
		F(i, 0, nt){
			if(i + (1<<j) > nt)continue;
			st[j][i] = min(st[j - 1][i], st[j - 1][i + (1<<(j-1))]);
		}
	}
}

int query(int l, int r){
	if(l > r)swap(l, r);
	--r;
	int j = lg[r - l + 1];
	return min(st[j][l], st[j][r - (1<<j) + 1]);
}

int main() {
    sync;
	lg[1] = 0;
	F(i, 2, N){
		lg[i] = lg[i - 1];
		while((1<<lg[i]) <= i)++lg[i];
		--lg[i];
	}
	int c0 = 0, c1 = 0;
	cin >> s >> t;
	ns = s.length();
	nt = t.length();
	if(s[0] == '1'){
		F(i, 0, ns)s[i] = '1' + '0' - s[i];
	}
	F(i, 0, ns){
		if(s[i] == '0')++c0;
		else ++c1;
	}
	calcz();
	sa = suffix_array(all(t));
	F(i, 0, nt)spos[sa[i]] = i;
	lcp = calc_lcp(nt, t.begin(), sa);
	build_st();
	int ans = 0;
	F(lens, 1, nt + 1){
		if(lens * 1ll * c0 + c1 > nt)
			break;
		int kek = nt - lens * c0;
		if(kek%c1 != 0)continue;
		int lent = kek/c1;
		int p0 = 0, p1 = 0;
		F(i, 0, ns)if(s[i] == '1')break; else p1 += lens;
		if(lens == lent && z[p1] >= lens)continue;
		bool g = 1;
		int cu = 0;
//		cerr << "! " << lens << endl;
		F(i, 0, ns){
			if(s[i] == '0'){
				if(z[cu] < lens){g = 0; break;}
				cu += lens;
			}
			else{
				if(cu != p1 && query(spos[p1], spos[cu]) < lent){g = 0; break;}
				cu += lent;
			}
		}
		if(g)++ans;
	}
	cout << ans;
	return 0;
}