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

const int MAXN = 1e2 + 5;

vi g[MAXN];

int prv[MAXN];
int sz[MAXN];

ll dp[MAXN][MAXN][MAXN];
ll dp_cur[MAXN][MAXN];

ll bin_pow(ll a, ll st){
	ll ans = 1ll;
	for(; st; st /= 2ll){
		if (st & 1){
			ans = (ans * a) % MOD;
		}
		a = (a * a) % MOD;
	}
	return ans;
}

ll get_rev(ll v){
	return bin_pow(v, MOD - 2ll);
}

ll rev[MAXN];
ll mul[MAXN][MAXN];
ll c[MAXN][MAXN];

ll ans[MAXN];

void dfs(int s){
	sz[s] = 1;
	dp[s][1][1] = 1ll;
	REP(i, 0, SZ(g[s])){
		int to = g[s][i];
		if (to != prv[s]){
			prv[to] = s;
			dfs(to);
			
			REPN(j1, 1, sz[s] + sz[to]){
				REPN(k1, 1, sz[s] + sz[to] - j1 + 1){
					dp_cur[j1][k1] = 0ll;
				}
			}
			
			REPN(j1, 1, sz[s]){
				REPN(k1, 1, sz[s] - j1 + 1){
					if (dp[s][j1][k1] == 0ll){
						continue;
					}
					REPN(j2, 1, sz[to]){
						REPN(k2, 1, sz[to] - j2 + 1){
							ll tmp1 = (dp[s][j1][k1] * dp[to][j2][k2]) % MOD;
							dp_cur[j1 + j2][k1] = (dp_cur[j1 + j2][k1] + tmp1) % MOD;
							dp_cur[j1 + j2 - 1][k1 + k2] = (dp_cur[j1 + j2 - 1][k1 + k2] + tmp1 * mul[k1][k2]) % MOD;
						}
					}
				}
			}
			
			REPN(j1, 1, sz[s] + sz[to]){
				REPN(k1, 1, sz[s] + sz[to] - j1 + 1){
					dp[s][j1][k1] = dp_cur[j1][k1];
				}
			}
			
			sz[s] += sz[to];
		}
	}
	
}

void solve(){
	int n, a, b;
	scanf("%d", &n);
	REP(i, 1, n){
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	REPN(i, 1, n){
		rev[i] = get_rev(i);
	}
	REPN(i, 1, n){
		REPN(j, 1, n){
			mul[i][j] = (rev[i] * rev[j]) % MOD;
			mul[i][j] = (mul[i][j] * (i + j)) % MOD;
		}
	}
	c[0][0] = 1ll;
	REPN(i, 1, n){
		c[i][0] = c[i][i] = 1ll;
		REP(j, 1, i){
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
	dfs(1);
	
	/*REPN(i, 1, n){
		REPN(j, 1, n){
			REPN(k, 1, n){
				if (dp[i][j][k]){
					printf("%d %d %d %lld\n", i, j, k, dp[i][j][k]);
				}
			}
		}
	}*/
	
	/*REPN(i, 1, n){
		ll ans = 0ll;
		REPN(j, 1, n){
			ans = (ans + dp[1][n - i + 1][j]) % MOD;
		}
		//ans = (ans * bin_pow(n, (i - 2 + MOD) % MOD));
		
		cout << ans << " ";
	}
	cout << endl;*/
	
	REPN(comp, 1, n){
		ans[comp] = 0ll;
		REPN(j, 1, n){
			ans[comp] = (ans[comp] + dp[1][comp][j]) % MOD;
		}
		//cout << comp << " " << ans[comp] << endl;
		if (comp >= 2){
			ans[comp] = (ans[comp] * bin_pow(n, (comp - 2 + MOD)  % MOD)) % MOD;
		} else {
			ans[comp] = (ans[comp] * get_rev(n)) % MOD;
		}
		REP(j, 1, comp){
			ll tmp = (ans[j] * c[n - j][n - comp]) % MOD;
			ans[comp] = (ans[comp] - tmp + MOD) % MOD;
		}
		//cout << comp << " " << ans[comp] << endl;
	}
	REPN(i, 1, n){
		cout << ans[n - i + 1] << " ";
	}
	cout << endl;
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