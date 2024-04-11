#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double DOUBLE;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x0 gray_cat_x0
#define y0 gray_cat_y0
#define x1 gray_cat_x1
#define y1 gray_cat_y1
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

const int MAXN = 3e5 + 5;

int a[MAXN];

int dp_v[2][MAXN];
ll dp_c[2][MAXN];
ll dp_s[2][MAXN];
int top[2];

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d", &a[i]);
	}
	reverse(a, a + n);
	top[0] = 1;
	dp_v[0][0] = a[0];
	dp_c[0][0] = 1;
	dp_s[0][0] = 0;
	//printf("%d: %d %lld %lld\n", 0, a[0], 1ll, 0ll);
	ll ans = 0;
	REP(i, 1, n) {
		int v = a[i];
		int ind = ((i - 1) & 1);
		top[ind ^ 1] = 0;
		for(int j = 0; j < top[ind]; ) {
			int cur_v = v / ((v + dp_v[ind][j] - 1) / dp_v[ind][j]);
			ll cur_c = 0;
			ll cur_s = 0;
			int r;
			for(r = j; r < top[ind] && v / ((v + dp_v[ind][r] - 1) / dp_v[ind][r]) == cur_v; r++){
				cur_c = (cur_c + dp_c[ind][r]) % MOD;
				cur_s = (cur_s + dp_s[ind][r] + dp_c[ind][r] * ((v - 1) / dp_v[ind][r])) % MOD;
			}
			dp_v[ind ^ 1][top[ind ^ 1]] = cur_v;
			dp_c[ind ^ 1][top[ind ^ 1]] = cur_c;
			dp_s[ind ^ 1][top[ind ^ 1]] = cur_s;
			//printf("%d [%d %d]: %d %lld %lld\n", i, j, r, dp_v[ind ^ 1][top[ind ^ 1]], dp_c[ind ^ 1][top[ind ^ 1]], dp_s[ind ^ 1][top[ind ^ 1]]);
			ans = (ans + dp_s[ind ^ 1][top[ind ^ 1]]) % MOD;
			top[ind ^ 1]++;
			j = r;
		}
		dp_v[ind ^ 1][top[ind ^ 1]] = v;
		dp_c[ind ^ 1][top[ind ^ 1]] = 1;
		dp_s[ind ^ 1][top[ind ^ 1]] = 0;
		//printf("%d: %d %lld %lld\n", i, dp_v[ind ^ 1][top[ind ^ 1]], dp_c[ind ^ 1][top[ind ^ 1]], dp_s[ind ^ 1][top[ind ^ 1]]);
		top[ind ^ 1]++;
	}
	printf("%lld\n", ans);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}