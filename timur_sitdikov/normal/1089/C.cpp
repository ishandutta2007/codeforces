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

const int MAXN = 505;

int g[MAXN][MAXN];
int gg[MAXN][MAXN], top_gg[MAXN];
int used[MAXN];
int mx[MAXN];

int values[MAXN], top_values;

char ss[MAXN];

void solve(){
	int n, m;
	scanf("%d", &n);
	REPN(i, 1, n) {
		REPN(j, 1, n) {
			g[i][j] = INF;
		}
		g[i][i] = 0;
	}
	scanf("%d", &m);
	REP(i, 0, m) {
		int c, a, b;
		scanf("%d%d", &c, &a);
		REP(i, 1, c) {
			scanf("%d", &b);
			g[a][b] = g[b][a] = 1;
			a = b;
		}
	}
	REPN(k, 1, n) {
		REPN(i, 1, n) {
			REPN(j, 1, n) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	REPN(i, 1, n) {
		REPN(j, 1, n) {
			if (g[i][j] == 1) {
				gg[i][top_gg[i]++] = j;
			}
		}
	}
	
	REPN(q, 1, n) {
		REPN(i, 1, n) {
			used[i] = 0;
		}
		while(true) {
			top_values = 0;
			REPN(i, 1, n) {
				if (!used[i]) {
					values[top_values++] = i;
				}
			}
			if (top_values == 1) {
				printf("%d\n", values[0]);
				fflush(stdout);
				scanf("%s", &ss[0]);
				assert(ss[0] == 'F');
				break;
			}
			
			REP(i, 0, top_values) {
				int s = values[i];
				mx[s] = 0;
				REP(j, 0, top_gg[s]) {
					int to = gg[s][j];
					int cur = 0;
					REP(k, 0, top_values) {
						if (g[s][values[k]] > g[to][values[k]]) {
							cur++;
						}
					}
					mx[s] = max(mx[s], cur);
				}
			}
			
			int ind = 0;
			REP(i, 1, top_values) {
				if (mx[values[i]] < mx[values[ind]]) {
					ind = i;
				}
			}
			ind = values[ind];
			printf("%d\n", ind);
			fflush(stdout);
			scanf("%s", &ss[0]);
			if (ss[0] == 'F') {
				break;
			}
			int nxt;
			scanf("%d", &nxt);
			REPN(i, 1, n) {
				if (g[ind][i] <= g[nxt][i]) {
					used[i] = 1;
				}
			}
		}
	}
}   

int main(){
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}