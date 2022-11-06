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
 
const int maxn = (int)625;
const int mod = (int)998244353; 
 
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
 
int ed [maxn][maxn]; 
 
vector <int> di [1500]; 
int vis [maxn]; 
int ans[maxn]; 
 
main(){
	rep (i, 0, maxn - 1) rep (j, 0, maxn - 1)ed[i][j] = 1e18; 
    cin.tie(0); ios_base::sync_with_stdio(0); 
	int n, m; cin >> n >> m; 
	
	rep (i, 1, m){
		int a, b, c; cin >> a >> b >> c; 
		ed[a][b] = c; 
	}
	
	rep (i, 0, n - 1){
		memset(vis,0,sizeof(vis)); memset(ans,0,sizeof(ans)); 
		int mini = 1e18; 
		rep (j, 0, n - 1){
			mini = min(mini, ed[i][j]); 
		}
		int sub = (mini - (mini % n)); 
		//if(sub==mini) sub-=n; 
		rep (j, 0, n - 1){
			ed[i][j] -= sub; 
		}
		int cur = 0; 
		di[0].pb(i); 
		
		int bl=0; 
		rep (j, 0, 2*n + 5){
			while (sz(di[j])){
				int node = di[j].back(); 
				di[j].pop_back(); 
				if (vis[node]) continue; 
				if (bl) vis[node] = 1; 
				if(node!=i) ans[node] = j; 
				rep (k,0,n-1){
					int real_k = (k + j) % n; 
					
					if (j + ed[node][k] <= 2*n + 2){
						di[j + ed[node][k]].pb(real_k); 
					}
				}
				if (bl) di[j + 1].pb((node + 1) % n); 
				bl=1; 
			}
		}
		rep (j, 0, n - 1){
			ed[i][j] += sub; 
		}
		rep (j, 0, 2*n + 10) di[j].clear(); 
		rep (j, 0, n - 1){
			if(i==j)cout << 0 << ' '; 
			else  cout << ans[j] + sub << ' ';
		}
		cout << '\n'; 
	}
    return 0; 
}