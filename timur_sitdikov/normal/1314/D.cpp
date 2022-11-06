#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef double DOUBLE;
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

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 10;
const int INF = 2e8 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 81;

int g[MAXN][MAXN];

pii dp[MAXN][MAXN][MAXN];

vi curs;
int ans;
int n, m;
int bad[MAXN];

void rec_sol() {
	if (SZ(curs) == m / 2) {
		curs.pb(0);
		int tt = 0;
		REP(l, 0, m / 2) {
			int a = curs[l], b = curs[l + 1];
			int ind;
			for(ind = 1; bad[dp[a][b][ind]._2]; ind++);
			tt += dp[a][b][ind]._1;
		}
		ans = min(ans, tt);
		curs.pop_back();
		return;
	}
	REP(i, 0, n) {
		bad[i]++;
		curs.pb(i);
		rec_sol();
		curs.pop_back();
		bad[i]--;
	}
}

void solve(){
	scanf("%d%d", &n, &m);
	//n = 80, m = 10;
	REP(i, 0, n) {
		REP(j, 0, n) {
			scanf("%d", &g[i][j]);
			//g[i][j] = 100000000;
		}
	}
	REP(i, 0, n) {
		g[i][i] = INF;
	}
	REP(i, 0, n) {
		REP(j, 0, n) {
			REP(k, 1, n) {	// Skip 0
				dp[i][j][k] = mp(g[i][k] + g[k][j], k);
			}
			sort(dp[i][j] + 1, dp[i][j] + n);
			dp[i][j][n] = mp(INF, n);
		}
	}
	ans = 1e9 + 10;
	bad[0] = 1;
	curs.pb(0);
	rec_sol();
	printf("%d\n", ans);
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