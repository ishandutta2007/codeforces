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
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 10;

int di[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dj[8] = {1, 0, -1, -1, -1, 0, 1, 1};

char g[MAXN][MAXN];
int dis[MAXN][MAXN];
int bad[MAXN][MAXN][100];

set<pair<int, pii> > qq;

void bfs(int i0, int j0) {
	REP(i, 0, 8) {
		REP(j, 0, 8) {
			dis[i][j] = INF;
		}
	}
	dis[i0][j0] = 0;
	qq.insert(mp(0, mp(i0, j0)));
	while(!qq.empty()) {
		pair<int, pii> pp = *(qq.begin());
		qq.erase(qq.begin());
		i0 = pp._2._1, j0 = pp._2._2;
		REP(t, pp._1, 50) {
			if (bad[i0][j0][t]) {
				break;
			}
			REP(k, 0, 8) {
				int i1 = i0 + di[k];
				int j1 = j0 + dj[k];
				if (i1 >= 0 && i1 < 8 && j1 >= 0 && j1 < 8 && !bad[i1][j1][t] && !bad[i1][j1][t + 1] && dis[i1][j1] > t + 1) {
					qq.erase(mp(dis[i1][j1], mp(i1, j1)));
					dis[i1][j1] = t + 1;
					qq.insert(mp(dis[i1][j1], mp(i1, j1)));
				}
			}
		}
	}
}

void solve(){
	REP(i, 0, 8) {
		scanf("%s", &g[i][0]);
		REP(j, 0, 8) {
			if (g[i][j] == 'S') {
				for(int k = i, t = 0; k < 8; k++, t++) {
					bad[k][j][t] = 1;
					/*if (k < 7) {
						bad[k + 1][j][t] = 1;
					}*/
				}
			}
		}
	}
	bfs(7, 0);
	/*REP(i, 0, 8) {
		REP(j, 0, 8) {
			printf("%d ", dis[i][j]);
		}
		putchar('\n');
	}*/
	if (dis[0][7] < INF) {
		printf("WIN\n");
	} else {
		printf("LOSE\n");
	}
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