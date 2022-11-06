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
const ll MOD = 998244353;

const int MAXN = 2e3 + 5;
const int DP_MOD = 11;

vi v1, v0;

ll dp1[2][MAXN][DP_MOD], dp0[2][MAXN][DP_MOD];

pii get_pp(int v){
	int len = 0, sum = 0;
	for(; v; len ^= 1, v /= 10){
		if (len){
			sum -= v % 10;
		} else {
			sum += v % 10;
		}
	}
	sum = (sum % DP_MOD + DP_MOD) % DP_MOD;
	if (!len){
		sum = (DP_MOD - sum) % DP_MOD;
	}
	return mp(sum, len);
}

void solve(){
	v1.clear();
	v0.clear();
	int n;
	scanf("%d", &n);
	REP(i, 0, 2){
		REPN(j, 0, n){
			REP(k, 0, DP_MOD){
				dp1[i][j][k] = dp0[i][j][k] = 0;
			}
		}
	}
	int v;
	REP(i, 0, n){
		scanf("%d", &v);
		pii pp = get_pp(v);
		if (pp._2 == 1){
			v1.pb(pp._1);
		} else {
			v0.pb(pp._1);
		}
	}
	dp1[0][0][0] = 1;
	int m = SZ(v1);
	REP(i, 0, m){
		int ind = i & 1;
		REPN(j, 0, m){
			REP(k, 0, DP_MOD){
				dp1[ind ^ 1][j][k] = 0;
			}
		}
		REPN(j, 0, i){
			REP(k, 0, DP_MOD){
				int k1 = (k + v1[i]) % DP_MOD;
				int k2 = (k - v1[i] + DP_MOD) % DP_MOD;
				dp1[ind ^ 1][j + 1][k1] = (dp1[ind ^ 1][j + 1][k1] + dp1[ind][j][k] * (j + 1)) % MOD;
				dp1[ind ^ 1][j][k2] = (dp1[ind ^ 1][j][k2] + dp1[ind][j][k] * (i + 1 - j)) % MOD;
			}
		}
	}
	dp0[0][0][0] = 1;
	int p = n - m;
	REP(i, 0, p){
		int ind = i & 1;
		REPN(j, 0, p){
			REP(k, 0, DP_MOD){
				dp0[ind ^ 1][j][k] = 0;
			}
		}
		REPN(j, 0, i){
			REP(k, 0, DP_MOD){
				int k1 = (k + v0[i]) % DP_MOD;
				int k2 = (k - v0[i] + DP_MOD) % DP_MOD;
				dp0[ind ^ 1][j + 1][k1] = (dp0[ind ^ 1][j + 1][k1] + dp0[ind][j][k] * (m / 2 + 1 + j)) % MOD;
				dp0[ind ^ 1][j][k2] = (dp0[ind ^ 1][j][k2] + dp0[ind][j][k] * ((m + 1) / 2 + (i - j))) % MOD;
			}
		}
		
		/*REPN(j, 0, i){
			REP(k, 0, DP_MOD){
				printf("%d %d %d %d\n", i + 1, j, k, dp0[ind ^ 1][j][k]);
			}
		}*/
	}
	
	ll ans = 0ll;
	
	int ind1 = m & 1;
	int ind0 = p & 1;
	REP(r1, 0, DP_MOD){
		int r2 = (DP_MOD - r1) % DP_MOD;
		REPN(j, 0, p){
			ans = (ans + dp1[ind1][(m + 1) / 2][r1] * dp0[ind0][j][r2]) % MOD;
		}
	}
	cout << ans << endl;
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();    
    }
}