//#pragma comment(linker, "/STACK:1024000000,1024000000")
/* vim: set fdm=marker */
//{{{
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int iinf = 0x7fffffff;
const ll linf = ~(1LL << 63);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<ll, int> mli;
typedef map<ll, ll> mll;
template<typename T>
inline T gcd(T a, T b) {
	if (a < 0) return gcd(-a, b);
	if (b < 0) return gcd(a, -b);
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll qpow(ll a, ll n, ll mod) {
	a %= mod;
	ll ans = 1LL;
	while (n) {
		if (n & 1) ans = (ans*a % mod);
		a = (a*a % mod);
		n >>= 1;
	}
	return ans;
}

inline ll rev(ll a, ll p) {
	return qpow(a, p - 2, p);
}

#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define rep(x, st, en) for(int x = st; x < en; x++)
#define rer(x, st, en) for(int x = st; x >= en; x--)
#define pb push_back
#define mp make_pair
#define dbgm(msg, var) cerr<<#msg<<" "<<#var<<" = "<<var<<endl; 
#define dbg(var) cerr<<#var<<" = "<<var<<endl;
#define X first
#define Y second
// build prefix sum
template<typename T>
inline void BPS(T* DST, T* SRC, int N, int s = 0) {
	DST[s] = SRC[s];
	rep(i, 1, N) DST[s + i] = DST[s + i - 1] + SRC[s + i];
}
inline int in() { int x; cin >> x; return x; }
#ifdef ALNDBG
namespace alndbg {
	clock_t s, e;
}
#endif

inline void tic() {
#ifdef ALNDBG
	alndbg::s = clock();
#endif
}

inline void toc() {
#ifdef ALNDBG
	alndbg::e = clock();
	cerr << 1000.0 * (alndbg::e - alndbg::s) / CLOCKS_PER_SEC << " ms" << endl;
#endif
}

//}}}

// -------------------- Spliters ------------------------
const int maxn = 4096;


unordered_map<int, int> igor[maxn];
unordered_map<int, int> zhenya[maxn];

inline int id(int l, int r) { return l * 4096 + r; }

int a[maxn];
int pref[maxn];
int n;
int cZhenya(int _id, int k);
int cIgor(int _id, int k) {
	int l = _id / 4096;
	int r = _id % 4096;
	int rem = r - l + 1;
	if (k > rem) return 0;

	auto res = igor[k].insert({ _id, 0 });

	if (!res.Y) return res.X->Y;
	int ans = 0;
	if (k == rem) {
		// take k
		ans = pref[l + k - 1] - pref[l - 1] + cZhenya(id(l + k, r), k);
	}
	else {
		ans = max(pref[l + k - 1] - pref[l - 1] + cZhenya(id(l + k, r), k), pref[l + k] - pref[l - 1] + cZhenya(id(l + k + 1, r), k + 1));
	}
	return res.X->Y = ans;
}

int cZhenya(int _id, int k) {
	int l = _id / 4096;
	int r = _id % 4096;
	int rem = r - l + 1;
	if (k > rem) return 0;

	auto res = zhenya[k].insert({ _id, 0 });
	if (!res.Y) return res.X->Y;

	int ans = 0;
	if (k == rem) {
		// take k
		ans = cIgor(id(l, r - k), k) - (pref[r] - pref[r - k]);
	}
	else {
		ans = min(cIgor(id(l, r - k), k) - (pref[r] - pref[r - k]), cIgor(id(l, r - k - 1), k + 1) - (pref[r] - pref[r - k - 1]));
	}
	return res.X->Y = ans;
}

int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a + i);
	BPS(pref, a, n);
	printf("%d\n", cIgor(id(0, n - 1), 1));
	_Exit(0);

	return 0;
}
// --USE C++11
// *-USE O