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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = (1 << 7) + 5;
const ll MOD = 1e9 + 7;

int n;

double p[MAXN];

struct matrix {
	double p[MAXN][MAXN];
};

matrix operator * (matrix &a, matrix &b) {
	matrix c;
	REP(i, 0, n){
		REP(j, 0, n){
			c.p[i][j] = 0.;
			REP(k, 0, n){
				c.p[i][j] += a.p[i][k] * b.p[k][j];
			}
		}
	}
	return c;
}

matrix bin_pow(matrix &v, int st){
	matrix a, ans;
	REP(i, 0, n){
		REP(j, 0, n){
			a.p[i][j] = v.p[i][j];
			ans.p[i][j] = (i == j ? 1.0 : 0.0);
		}
	}
	/*REP(i, 0, n){
		REP(j, 0, n){
			printf("%d %d %lf\n", i, j, ans.p[i][j]);
		}
	}*/
	for(; st; st >>= 1){
		if (st & 1){
			ans = ans * a;
		}
		/*REP(i, 0, n){
			REP(j, 0, n){
				printf("%d %d %lf\n", i, j, a.p[i][j]);
			}
		}*/
		a = a * a;
	}
	return ans;
}

void solve(){
	int st;
	scanf("%d%d", &st, &n);
	n++;
	REP(i, 0, n){
		scanf("%lf", &p[i]);
	}
	for(; n & (n - 1); n++);
	matrix pp;
	REP(i, 0, n){
		REP(j, 0, n){
			pp.p[i][j] = p[i ^ j];//p[i] * p[i ^ j];
			//printf("%d %d %lf\n", i, j, pp.p[i][j]);
		}
	}
	matrix tt = bin_pow(pp, st);
	/*REP(i, 0, n){
		REP(j, 0, n){
			printf("%d %d %lf\n", i, j, tt.p[i][j]);
		}
	}*/
	printf("%.12lf\n", 1. - tt.p[0][0]);
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