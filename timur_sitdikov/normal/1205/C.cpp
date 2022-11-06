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
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 55;

int g[MAXN][MAXN];

int n;

int di[8] = {2, 1, 0, -2, -1, 0};
int dj[8] = {0, 1, 2, 0, -1, -2};

int ask(int i1, int j1, int i2, int j2) {
	printf("? %d %d %d %d\n", i1, j1, i2, j2);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}

int is_good(int i1, int j1) {
	return i1 > 0 && j1 > 0 && i1 <= n && j1 <= n;
}

void solve(){
	scanf("%d", &n);
	g[1][1] = 1;
	REPN(i, 1, n) {
		REPN(j, 1, n) {
			if ((i + j) % 2 == 1) {
				continue;
			}
			if (i == 1 && j == 1 || i == n && j == n) {
				continue;
			}
			int i1 = i - 1, j1 = j - 1;
			if (i == 1) {
				i1 = i;
				j1 = j - 2;
			} else if (j == 1) {
				j1 = j;
				i1 = i - 2;
			}
			g[i][j] = g[i1][j1] ^ ask(i1, j1, i, j) ^ 1;
		}
	}
	int i1, j1;
	REPN(i, 1, n - 2) {
		REPN(j, 1, n - 2) {
			if (g[i][j] == 1 && g[i + 2][j + 2] == 0) {
				i1 = i;
				j1 = j;
			}
		}
	}
	REPN(i, 1, n) {
		REPN(j, 1, n) {
			if ((i + j) % 2 == 1) {
				g[i][j] = -1;
			}
		}
	}
	if (g[i1 + 1][j1 + 1] == 1) {
		if (ask(i1, j1, i1 + 2, j1 + 1)) {
			g[i1 + 2][j1 + 1] = 1;
		} else if (ask(i1 + 1, j1, i1 + 2, j1 + 1)) {
			g[i1 + 1][j1] = 0;
			g[i1 + 2][j1 + 1] = 0;
		} else if (ask(i1 + 1, j1, i1 + 2, j1 + 2)) {
			g[i1 + 1][j1] = 0;
			g[i1 + 2][j1 + 1] = 1;
		} else {
			g[i1 + 1][j1] = 1;
			g[i1 + 2][j1 + 1] = 0;
		}
	} else {
		if (ask(i1 + 1, j1, i1 + 2, j1 + 2)) {
			g[i1 + 1][j1] = 0;
		} else if (ask(i1 + 1, j1, i1 + 2, j1 + 1)) {
			g[i1 + 1][j1] = 1;
			g[i1 + 2][j1 + 1] = 1;
		} else if (ask(i1, j1, i1 + 2, j1 + 1)) {
			g[i1 + 1][j1] = 0;
			g[i1 + 2][j1 + 1] = 1;
		} else {
			g[i1 + 1][j1] = 1;
			g[i1 + 2][j1 + 1] = 0;
		}
	}
	
	while(1) {
		int fl = 0;
		REPN(i, 1, n) {
			REPN(j, 1, n) {
				if (g[i][j] == -1) {
					REP(k, 0, 6) {
						int i1 = i + di[k];
						int j1 = j + dj[k];
						if (is_good(i1, j1) && g[i1][j1] != -1) {
							g[i][j] = g[i1][j1] ^ ask(min(i, i1), min(j, j1), max(i, i1), max(j, j1)) ^ 1;
							fl = 1;
							break;
						}
					}
				}
			}
		}
		if (!fl) {
			break;
		}
	}
	
	printf("!\n");
	REPN(i, 1, n) {
		REPN(j, 1, n) {
			printf("%d", g[i][j]);
		}
		putchar('\n');
	}
	fflush(stdout);
}   

int main(){
/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif*/
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}