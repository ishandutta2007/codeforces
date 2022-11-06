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

const int MAXN = 105, MAXM = 1e4 + 5;

char c[MAXN][MAXM];

int dl[MAXN][MAXM], dr[MAXN][MAXM];
ll d[MAXM];

void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, 0, n) {
		scanf("%s", &c[i][0]);
	}
	REP(i, 0, n) {
		REP(j, 0, m) {
			dl[i][j] = dr[i][j] = INF;
		}
	}
	REP(i, 0, n) {
		REP(j, 0, 2 * m) {
			dl[i][j % m] = min(dl[i][j % m], dl[i][(j + m - 1) % m] + 1);
			if (c[i][j % m] == '1') {
				dl[i][j % m] = 0;
			}
		}
		for(int j = 2 * m - 1; j >= 0; j--) {
			dr[i][j % m] = min(dr[i][j % m], dr[i][(j + 1) % m] + 1);
			if (c[i][j % m] == '1') {
				dr[i][j % m] = 0;
			}
		}
	}
	ll ans = INF;
	REP(j, 0, m) {
		REP(i, 0, n) {
			d[j] += min(dl[i][j], dr[i][j]);
		}
		ans = min(ans, d[j]);
	}
	if (ans >= INF) {
		ans = -1;
	}
	cout << ans << endl;
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