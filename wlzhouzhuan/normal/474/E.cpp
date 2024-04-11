#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define loop(s, v, it) for (s::iterator it = v.begin(); it != v.end(); it++)
#define cont(i, x) for (int i = head[x]; i; i = e[i].nxt)
#define clr(a) memset(a, 0, sizeof(a))
#define ass(a, sum) memset(a, sum, sizeof(a))
#define lowbit(x) (x & -x)
#define all(x) x.begin(), x.end()
#define ub upper_bound
#define lb lower_bound
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define iv inline void
#define enter cout << endl
#define siz(x) ((int)x.size())
#define file(x) freopen(#x".in", "r", stdin),freopen(#x".out", "w", stdout)
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair <int, int> pii ;
typedef vector <int> vi ;
typedef vector <pii> vii ;
typedef queue <int> qi ;
typedef queue <pii> qii ;
typedef set <int> si ;
typedef map <int, int> mii ;
typedef map <string, int> msi ;
const int N = 100010 ;
const int INF = 0x3f3f3f3f ;
const int iinf = 1 << 30 ;
const ll linf = 2e18 ;
const int MOD = 1000000007 ;
const double eps = 1e-7 ;
void print(int x) { cout << x << endl ; exit(0) ; }
void PRINT(string x) { cout << x << endl ; exit(0) ; }
void douout(double x){ printf("%lf\n", x + 0.0000000001) ; }

int n, d, tt ;
int tmp[N], a[N], bit1[N], bit2[N], ans[N], to[N] ;

void lsh() {
	rep(i, 1, n) tmp[i] = a[i] ;
	sort(tmp + 1, tmp + n + 1) ;
	tt = unique(tmp + 1, tmp + n + 1) - (tmp + 1) ;
}

int Max(int a, int b) {
	return ans[a] < ans[b] ? b : a ;
}

void add1(int x, int y) {
	for (; x <= tt; x += lowbit(x)) bit1[x] = Max(bit1[x], y) ;
}

int ask1(int x) {
	int ans = 0 ;
	for (; x; x -= lowbit(x)) ans = Max(bit1[x], ans) ;
	return ans ;
}

void add2(int x, int y) {
	for (; x <= tt; x += lowbit(x)) bit2[x] = Max(bit2[x], y) ;
}

int ask2(int x) {
	int ans = 0 ;
	for (; x; x -= lowbit(x)) ans = Max(bit2[x], ans) ;
	return ans ;
}

signed main(){
	scanf("%lld%lld", &n, &d) ;
	rep(i, 1, n) scanf("%lld", &a[i]) ;
	lsh() ;
	per(i, n, 1) {
		int x = lb(tmp + 1, tmp + tt + 1, a[i] + d) - tmp ;
		int y = ub(tmp + 1, tmp + tt + 1, a[i] - d) - (tmp + 1) ;
		int res = Max(ask1(y), ask2(tt - x + 1)) ;
		ans[i] = ans[res] + 1 ;
		to[i] = res ;
		int pos = lb(tmp + 1, tmp + tt + 1, a[i]) - tmp ;
		add1(pos, i) ;
		add2(tt - pos + 1, i) ;
	}
//	rep(i, 1, n) cout << ans[i] << " " ; enter ;
	int s = 0 ;
	rep(i, 1, n) s = Max(s, i) ;
	printf("%lld\n", ans[s]) ;
	while (s) {
		printf("%lld ", s) ;
		s = to[s] ;
	}
	enter ;
	return 0 ;
}