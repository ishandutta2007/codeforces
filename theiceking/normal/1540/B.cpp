#include <bits/stdc++.h>
 
using namespace std; 
 
#define int long long 
 
 
template <typename T> 
void print_vec(const vector<T>& v, bool newline = true) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    if (newline) {
        cout << "\n";
    }
}
 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
 
const int maxn = (int)1e3 + 105;
const int mod = (int)1e9 + 7; 
 
#define sz(x) ((int)(x.size()))
 
#define pb push_back
#define rep(i,a,b) for (int i = (a); i <= (b); i++)
#define repr(i,a,b) for (int i = (a); i >= (b); i--)
 
int fact_setup=0; int * fact; 
 
int ex (int a, int b){
    if(b==0)return 1; int e = ex(a,b/2); e=(1ll*e*e)%mod; if(b&1)e=(1ll*e*a)%mod; return e;
}
int inv (int a){
    return ex(a, mod - 2); 
}
int choose (int a, int b){
    if(!fact_setup){
        fact_setup=1; 
        fact = new int [maxn]; 
        fact[0]=1; rep (i,1,maxn-1) fact[i]=(i*fact[i-1])%mod; 
    }
    if(a<b)return 0; 
    int num = fact[a]; 
    int denom = (fact[b] * fact[a - b]) % mod; 
    return (num * inv(denom)) % mod; 
}
 
#define pii pair <int, int> 
#define pvi pair <vector <int>, int> 
 
#define pai array <int,2>
#define pdi array <double, 2> 
#define pdt array <double, 3>
 
#define pti array <int,3>
#define pfi array <int,4>
 
#define all(v) v.begin(), v.end()
 
vector <int> ed [maxn]; 

int dp [215][215]; 
int pa[215]; 
int dist [215]; 
int lca[215][215]; 

void go (int node, int p = 0){
	if (p) dist[node] = dist[p] + 1; 
	pa[node] = p; 
	for (int i : ed[node]){
		if (i == p) continue; 
		go(i,  node); 
	}
}
int lc (int i, int j){
	if (lca[i][j] != -1) return lca[i][j]; 
	
	if (i == j) return lca[i][j] = i; 
	if (dist[i] > dist[j]) return lca[i][j] = lc (pa[i], j); 
	else return lca[i][j] = lc(i, pa[j]); 
}
main(){
    cin.tie(0); ios_base::sync_with_stdio(0); 
	choose(2, 1); 
	int n; cin >> n; 
	rep (i, 1, n - 1){
		int a, b; cin >> a >> b; 
		ed[a].pb(b); ed[b].pb(a); 
	}
	rep (i, 1, 214) dp[0][i] = 1; 
	
	rep (i, 1, 210){
		rep (j, 1, 210){
			dp[i][j] = ((inv(2) * dp[i - 1][j])%mod) + ((inv(2) * dp[i][j - 1])%mod); 
			dp[i][j] %= mod; 
		}
	}
	int ans = 0; 
	rep (i, 1, n){
		memset(lca, -1, sizeof(lca)); 
		
		dist[i] = 0; 
		go (i, 0); 
		rep (i, 1, n){
			rep (j, 1, n){
				lc(i, j); 
			}
		}
		int tot = 0; 
		rep (j, 1, n){
			rep (k, 1, j - 1){
				int up = dist[lca[j][k]]; 
				tot += dp[dist[j] - up][dist[k] - up]; 
				tot %= mod; 
			}
		}
		ans = (ans + tot) % mod; 
	}
	ans  %= mod; 
	cout << (ans * inv(n)) % mod; 
    return 0; 
}