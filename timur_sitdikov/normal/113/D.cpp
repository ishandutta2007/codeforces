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

const int MAXN = 23;

int g[MAXN][MAXN];

DOUBLE p[MAXN];

DOUBLE m[MAXN * MAXN][MAXN * MAXN];

int ind[MAXN][MAXN], ind1[MAXN][MAXN];
int ii[MAXN * MAXN], jj[MAXN * MAXN];
int deg[MAXN];

void build_matr(int n){
	REP(i, 0, n) {
		REP(j, 0, n) {
			if (i != j) {
				m[ind[i][j]][ind[i][j]] = 1. - p[i] * p[j];
			}
		}
	}
	REP(i, 0, n) {
		REP(j, 0, n) {
			if (i != j) {
				REP(i1, 0, n) {
					if (g[i][i1]) {
						m[ind[i][j]][ind[i1][j]] = -(1. - p[i]) / deg[i] * p[j];
					}
				}
				REP(j1, 0, n) {
					if (g[j][j1]) {
						m[ind[i][j]][ind[i][j1]] = -p[i] * (1. - p[j]) / deg[j];
					}
				}
				REP(i1, 0, n) {
					REP(j1, 0, n) {
						if (g[i][i1] && g[j][j1]) {
							m[ind[i][j]][ind[i1][j1]] = -(1. - p[i]) / deg[i] * (1. - p[j]) / deg[j];
						}
					}
				}
			}
		}
	}
	
	/*printf("*************\nBUILD\n");
	REP(i, 0, n * n) {
		REP(j, 0, n * n) {
			printf("%.12lf ", m[i][j]);
		}
		putchar('\n');
	}
	printf("\n");*/
}

void go(int n) {
	REP(k, 0, n * (n - 1)) {
		int pos = k;
		REP(i, k, n * (n - 1)) {
			if (abs(m[i][k]) > abs(m[pos][k])) {
				pos = i;
			}
		}
		pos = k;
		if (pos != k) {
			swap(ii[pos], ii[k]);
			swap(jj[pos], jj[k]);
			REP(j, k, n * n) {
				swap(m[pos][j], m[k][j]);
			}
		}
		REP(i, k + 1, n * (n - 1)) {
			REP(j, k + 1, n * n) {
				m[i][j] -= m[i][k] / m[pos][k] * m[pos][j];
			}
			m[i][k] = 0;
		}
	}
	
	/*printf("*************\nGO\n");
	REP(i, 0, n * n) {
		REP(j, 0, n * n) {
			printf("%.12lf ", m[i][j]);
		}
		putchar('\n');
	}
	printf("\n");*/
}

DOUBLE ans[MAXN];
DOUBLE b[MAXN * MAXN];
double res[MAXN * MAXN];

void eval(int n, int pos, int s, int f) {
	REP(i, 0, n * (n - 1)) {
		b[i] = -m[i][n * (n - 1) + pos];
	}
	for(int i = n * (n - 1) - 1; i >= 0; i--) {
		res[i] = b[i] / m[i][i];
		for(int k = i - 1; k >= 0; k--) {
			b[k] -= res[i] * m[k][i];
		}
	}
	REP(i, 0, n * n) {
		if (ii[i] == s && jj[i] == f) {
			ans[pos] = res[i];
		}
	}
}

void solve(){
	int n, m, s, f;
	scanf("%d%d%d%d", &n, &m, &s, &f);
	s--, f--;
	if (s == f) {
		REP(i, 0, n) {
			if (i == s) {
				printf("1.0 ");
			} else {
				printf("0.0 ");
			}
		}
		putchar('\n');
		return;
	}
	REP(i, 0, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a][b] = g[b][a] = 1;
		deg[a]++;
		deg[b]++;
	}
	REP(i, 0, n) {
		double x;
		scanf("%lf", &x);
		p[i] = x;
	}
	int top = 0;
	REP(i, 0, n) {
		REP(j, 0, n) {
			if (i != j) {
				ii[top] = i;
				jj[top] = j;
				ind[i][j] = top++;
			}
		}
	}
	REP(i, 0, n) {
		ii[top] = i;
		jj[top] = i;
		ind[i][i] = top++;
	}
	/*REP(i, 0, n * n) {
		REP(j, 0, n * n) {
			ind1[i][j] = ind[i][j];
		}
	}*/
	build_matr(n);
	go(n);
	REP(i, 0, n) {
		eval(n, i, s, f);
	}
	REP(i, 0, n) {
		printf("%.12lf\n", (double)ans[i]);
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