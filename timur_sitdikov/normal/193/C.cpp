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

const int MAXN = 4e5 + 5;

char s[4][MAXN];

int g[4][4];

void solve(){
	REP(i, 0, 4) {
		REP(j, i + 1, 4) {
			scanf("%d", &g[i][j]);
			g[j][i] = g[i][j];
		}
	}
	REP(i, 0, 4) {
		REP(j, 0, 4) {
			// printf("%d %d: %d\n", i, j, g[i][j]);
			REP(k, 0, 4) {
				if (g[i][j] > g[i][k] + g[k][j]) {
					printf("-1\n");
					return;
				}
				if ((g[i][j] + g[i][k] + g[j][k]) & 1) {
					printf("-1\n");
					return;
				}
			}
		}
	}
	int y = (g[0][1] + g[0][2] - g[1][2]) / 2;
	int x = (g[0][1] + g[1][2] - g[0][2]) / 2;
	int z = g[1][2] - x;
	// printf("%d %d %d\n", x, y, z);
	if (x < 0 || y < 0 || z < 0) {
		printf("-1\n");
		return;
	}
	REP(i, 0, x) {
		s[0][i] = 'a';
		s[1][i] = 'b';
		s[2][i] = 'a';
	}
	REP(i, 0, y) {
		s[0][x + i] = 'a';
		s[1][x + i] = 'b';
		s[2][x + i] = 'b';
	}
	REP(i, 0, z) {
		s[0][x + y + i] = 'a';
		s[1][x + y + i] = 'a';
		s[2][x + y + i] = 'b';
	}
	int lim = 100005;
	REPN(w, 0, lim) {
		int v = (g[0][3] + g[1][3] - g[0][1]) / 2 - w;
		int q = (g[0][3] + g[2][3] - g[0][2]) / 2 - w;
		int r = (g[1][3] + g[2][3] - g[1][2]) / 2 - w;
		int p = x - q;
		int t = y - r;
		int u = z - v;
		if (p < 0 || q < 0 || r < 0 || t < 0 || u < 0 || v < 0) {
			continue;
		}
		int offset = 0;
		REP(i, 0, p) {
			s[3][offset + i] = 'a';
		}
		offset += p;
		REP(i, 0, q) {
			s[3][offset + i] = 'b';
		}
		offset += q;
		REP(i, 0, r) {
			s[3][offset + i] = 'a';
		}
		offset += r;
		REP(i, 0, t) {
			s[3][offset + i] = 'b';
		}
		offset += t;
		REP(i, 0, u) {
			s[3][offset + i] = 'a';
		}
		offset += u;
		REP(i, 0, v) {
			s[3][offset + i] = 'b';
		}
		offset += v;
		REP(i, 0, w) {
			s[0][offset + i] = 'a';
			s[1][offset + i] = 'a';
			s[2][offset + i] = 'a';
			s[3][offset + i] = 'b';
		}
		offset += w;
		printf("%d\n", offset);
		REP(i, 0, 4) {
			printf("%s\n", s[i]);
		}
		return;
	}
	printf("-1\n");
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