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
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 1e5 + 5, MAXD = 255, MAXSZ = 26;

char c[MAXN];

int nxt[MAXN][MAXSZ];

int dp[MAXD][MAXD][MAXD];

int cnt[10];

int vv[10][MAXD];

void solve(){
	int n, q;
	scanf("%d%d%s", &n, &q, &c[1]);
	REP(i, 0, MAXSZ) {
		nxt[n][i] = INF;
	}
	for(int i = n - 1; i >= 0; i--) {
		REP(j, 0, MAXSZ) {
			nxt[i][j] = nxt[i + 1][j];
		}
		nxt[i][c[i + 1] - 'a'] = i + 1;
	}
	while(q--) {
		char s[10], sym[10];
		int t;
		scanf("%s%d", &s[0], &t);
		t--;
		if (s[0] == '-') {
			cnt[t]--;
		} else {
			scanf("%s", &sym[0]);
			vv[t][cnt[t]++] = sym[0] - 'a';
			if (t == 0) {
				int i = cnt[0];
				REPN(j, 0, cnt[1]) {
					REPN(k, 0, cnt[2]) {
						int &value = dp[i][j][k];
						value = INF;
						if (i && dp[i - 1][j][k] < INF) {
							value = min(value, nxt[dp[i - 1][j][k]][vv[0][i - 1]]);
						}
						if (j && dp[i][j - 1][k] < INF) {
							value = min(value, nxt[dp[i][j - 1][k]][vv[1][j - 1]]);
						}
						if (k && dp[i][j][k - 1] < INF) {
							value = min(value, nxt[dp[i][j][k - 1]][vv[2][k - 1]]);
						}
					}
				}
			} else if (t == 1) {
				int j = cnt[1];
				REPN(i, 0, cnt[0]) {
					REPN(k, 0, cnt[2]) {
						int &value = dp[i][j][k];
						value = INF;
						if (i && dp[i - 1][j][k] < INF) {
							value = min(value, nxt[dp[i - 1][j][k]][vv[0][i - 1]]);
						}
						if (j && dp[i][j - 1][k] < INF) {
							value = min(value, nxt[dp[i][j - 1][k]][vv[1][j - 1]]);
						}
						if (k && dp[i][j][k - 1] < INF) {
							value = min(value, nxt[dp[i][j][k - 1]][vv[2][k - 1]]);
						}
					}
				}
			} else if (t == 2) {
				int k = cnt[2];
				REPN(i, 0, cnt[0]) {
					REPN(j, 0, cnt[1]) {
						int &value = dp[i][j][k];
						value = INF;
						if (i && dp[i - 1][j][k] < INF) {
							value = min(value, nxt[dp[i - 1][j][k]][vv[0][i - 1]]);
						}
						if (j && dp[i][j - 1][k] < INF) {
							value = min(value, nxt[dp[i][j - 1][k]][vv[1][j - 1]]);
						}
						if (k && dp[i][j][k - 1] < INF) {
							value = min(value, nxt[dp[i][j][k - 1]][vv[2][k - 1]]);
						}
					}
				}
			}
		}
		if (dp[cnt[0]][cnt[1]][cnt[2]] < INF) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
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