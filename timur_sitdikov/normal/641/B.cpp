#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<long double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 2e5 + 5, MAXC = 105;
const ll MOD = 1e9 + 7;

int vv[MAXC][MAXC];

int tt[MAXN], r[MAXN], c[MAXN], x[MAXN];

void solve(){
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	REP(i, 0, q){
		scanf("%d", &tt[i]);
		if (tt[i] == 1){
			scanf("%d", &r[i]);
		} else if (tt[i] == 2){
			scanf("%d", &c[i]);
		} else {
			scanf("%d%d%d", &r[i], &c[i], &x[i]);
		}
	}
	for(int k = q - 1; k >= 0; k--){
		if (tt[k] == 3){
			vv[r[k]][c[k]] = x[k];
		} else if (tt[k] == 1){
			for(int i = r[k]; i <= r[k]; i++){
				for(int j = m + 1; j >= 2; j--){
					vv[i][j] = vv[i][j - 1];
				}
				vv[i][1] = vv[i][m + 1];
			}
		} else if (tt[k] == 2){
			for(int j = c[k]; j <= c[k]; j++){
				for(int i = n + 1; i >= 2; i--){				
					vv[i][j] = vv[i - 1][j];
				}
				vv[1][j] = vv[n + 1][j];
			}
		}
		/*REPN(i, 1, n){
			REPN(j, 1, m){
				printf("%d ", vv[i][j]);
			}
			putchar('\n');
		}*/
	}
	REPN(i, 1, n){
		REPN(j, 1, m){
			printf("%d ", vv[i][j]);
		}
		putchar('\n');
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