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

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 205, MAXR = 6;

int dp[MAXR][MAXN][MAXN][MAXR];
int prv_1[MAXR][MAXN][MAXN][MAXR], prv_2[MAXR][MAXN][MAXN][MAXR];
int dp_best_1[MAXN][MAXN], dp_best_2[MAXN][MAXN];
int cnt[MAXR];

void update(int r, int v, int i, int j, int vi, int vj) {
	int i1 = i + vi;
	int j1 = j + vj;
	int v1 = (vi > vj ? 1 : 0);
	if (i1 < MAXN && j1 < MAXN && !dp[r + 1][i1][j1][v + v1]) {
		dp[r + 1][i1][j1][v + v1] = 1;
		prv_1[r + 1][i1][j1][v + v1] = i;
		prv_2[r + 1][i1][j1][v + v1] = j;
	}
}

void solve(){
	cnt[1] = cnt[2] = cnt[3] = cnt[4] = 25;
	cnt[5] = 15;
	REP(k, 0, MAXR) {
		REP(i, 0, MAXN) {
			REP(j, 0, MAXN) {
				REPN(l, 0, k) {
					dp[k][i][j][l] = 0;
					prv_1[k][i][j][l] = -1;
					prv_2[k][i][j][l] = -1;
				}
				dp_best_1[i][j] = -1;
				dp_best_2[i][j] = -1;
			}
		}
	}
	dp[0][0][0][0] = 1;
	REP(k, 1, MAXR) {
		REP(i, 0, MAXN) {
			REP(j, 0, MAXN) {
				REPN(l, 0, k - 1) {
					if (dp[k - 1][i][j][l] && l < 3 && k - 1 - l < 3) {
						REP(c, 0, cnt[k] - 1) {
							update(k - 1, l, i, j, cnt[k], c);
							update(k - 1, l, i, j, c, cnt[k]);
						}
						REP(c, cnt[k] - 1, MAXN) {
							update(k - 1, l, i, j, c + 2, c);
							update(k - 1, l, i, j, c, c + 2);
						}
					}
				}
			}
		}
	}
	
	/*printf("1 0 25 0 - %d\n", dp[1][0][25][0]);
	printf("2 0 50 0 - %d\n", dp[2][0][50][0]);
	printf("3 0 75 0 - %d\n", dp[3][0][75][0]);*/
	
	REP(k, 0, MAXR) {
		REP(i, 0, MAXN) {
			REP(j, 0, MAXN) {
				REPN(l, 0, k) {
					if (dp[k][i][j][l] == 1 && (l == 3 || k - l == 3) && (dp_best_1[i][j] == -1 || (l - (k - l) > dp_best_2[i][j] - (dp_best_1[i][j] - dp_best_2[i][j])))) {
						dp_best_1[i][j] = k;
						dp_best_2[i][j] = l;
					}
				}
			}
		}
	}
	int t;
	scanf("%d", &t);
	REP(i, 0, t) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (dp_best_1[a][b] == -1) {
			printf("Impossible\n");
			continue;
		}
		int c = dp_best_1[a][b], d = dp_best_2[a][b];
		printf("%d:%d\n", d, c - d);
		vector<pii> vv;
		for(; c != 0; c--) {
			int di = a - prv_1[c][a][b][d];
			int dj = b - prv_2[c][a][b][d];
			vv.pb(mp(di, dj));
			a -= di;
			b -= dj;
			if (di > dj) {
				d--;
			}
		}
		reverse(BE(vv));
		REP(j, 0, SZ(vv)) {
			printf("%d:%d ", vv[j]._1, vv[j]._2);
		}
		putchar('\n');
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