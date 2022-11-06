#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
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

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll INF = 1e12;
const ll MOD = 1e9 + 7;

const int MAXN = 75, MAXC = 17;

int g[MAXN][MAXN];
int l, r;
int n;

int used[MAXN];
int col;
vi vv[MAXN];

ll dp[1 << MAXC][MAXN];
int ind[MAXN];

ll ans[MAXN];

int used_dis[MAXN];

void dfs(int s) {
	used[s] = col;
	vv[col].pb(s);
	REPN(i, 1, n) {
		if (g[s][i] == l && !used[i]) {
			dfs(i);
		}
	}
}

void solve(){
	int m;
	cin >> n >> m >> l >> r;
	REP(i, 0, m) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = c;
	}
	REPN(i, 1, n) {
		if (!used[i]) {
			col++;
			dfs(i);
		}
	}
	REPN(i, 1, n) {
		REPN(j, 1, n) {
			if (g[i][j] == r && used[i] == used[j]) {
				g[i][j] = 0;
			}
		}
	}
	
	int lim = 0;
	REPN(i, 1, col) {
		if (SZ(vv[i]) >= 4) {
			ind[i] = lim++;
		} else {
			ind[i] = -1;
		}
	}
	
	REP(i, 0, 1 << lim) {
		REPN(j, 1, n) {
			dp[i][j] = INF;
		}
	}
	
	if (ind[used[1]] == -1) {
		dp[0][1] = 0;
	} else {
		dp[1 << ind[used[1]]][1] = 0;
	}
	
	REPN(i, 1, n) {
		ans[i] = INF;
	}
	
	REP(i, 0, 1 << lim) {
		REPN(j, 1, n) {
			used_dis[j] = 0;
		}
		REPN(j, 1, n) {
			int s = -1;
			REPN(k, 1, n) {
				if (!used_dis[k] && (s == -1 || dp[i][k] < dp[i][s])) {
					s = k;
				}
			}
			if (s == -1 || dp[i][s] == INF) {
				break;
			}
			
			//cout << i << " " << s << endl;
			
			used_dis[s] = 1;
			int ind_j = ind[used[s]];
			REPN(k, 1, n) {
				if (g[s][k]) {
					int ind_k = ind[used[k]];
					if (ind_k == -1 || ind_k == ind_j) {
						dp[i][k] = min(dp[i][k], dp[i][s] + g[s][k]);
					} else if (!(i & (1 << ind_k))) {
						dp[i ^ (1 << ind_k)][k] = min(dp[i ^ (1 << ind_k)][k], dp[i][s] + g[s][k]);
					}
				}
			}
			
			ans[s] = min(ans[s], dp[i][s]);
		}
	}
	
	REPN(i, 1, n) {
		cout << ans[i] << " ";
	}
	cout << endl;
	
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