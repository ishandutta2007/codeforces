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

vi g[MAXN];
ll dp_tot[MAXN], dp_step[MAXN];
ll v[MAXN];

void dfs(int s, int p) {
	ll mn_tot = LL_INF, lcm_step = 0, cnt = 0;
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (to != p) {
			dfs(to, s);
			cnt++;
			mn_tot = min(mn_tot, dp_tot[to]);
			if (cnt == 1) {
				lcm_step = dp_step[to];
			} else if (!lcm_step || !dp_step[to]) {
				lcm_step = 0;
			} else {
				ll g = gcd(lcm_step, dp_step[to]);
				lcm_step = lcm_step / g * dp_step[to];
			}
		}
	}
	if (cnt == 0) {
		dp_tot[s] = v[s];
		dp_step[s] = 1;
	} else {
		bool has_overflow = false;
		REP(i, 0, SZ(g[s])) {
			int to = g[s][i];
			if (to != p && dp_step[to] && lcm_step % dp_step[to]) {
				has_overflow = true;
			}
		}
		if (has_overflow || !lcm_step) {
			dp_tot[s] = 0;
			dp_step[s] = 0;
		} else {
			dp_tot[s] = mn_tot / lcm_step * lcm_step * cnt;
			dp_step[s] = lcm_step * cnt;
		}
	}
}

void solve(){
	int n;
	scanf("%d", &n);
	ll sum = 0;
	REPN(i, 1, n) {
		scanf("%lld", &v[i]);
		sum += v[i];
	}
	REP(i, 1, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1, 0);
	printf("%lld\n", sum - dp_tot[1]);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}