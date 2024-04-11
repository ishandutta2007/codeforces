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
 
const int maxn = (int)5e5 + 305;
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

int bad[maxn]; 
vector<vector<char> > arr;
vector<int>ed [maxn], rev[maxn]; 


int n, m; 
int has (int a, int b){
	return a*m+b; 
}
int xx[4]={1,-1,0,0}; 
int yy[4]={0,0,1,-1}; 

bool fin (int a, int b){
	if (a<0||b<0||a>=n||b>=m) return 0; 
	if(bad[has(a,b)]) return 0; 
	return 1; 
}
int vis[maxn], scc[maxn]; 
int no [maxn]; 


vector<int>stck ;
int ori=-1; 
void go (int node){
	vis[node]=1; 
	for (int i : ed[node]){
		if (vis[i]) continue; go (i); 
	}
	stck.pb(node); 
}
void go2 (int node, int orig){
	vis[node]=1; 
	scc[node] = orig; 
	for (int i : rev[node]){
		if (vis[i]) continue; 
		go2(i, orig); 
	}
}
main(){
	memset(scc,-1,sizeof(scc));
    cin.tie(0); ios_base::sync_with_stdio(0); 
	cin >> n >> m; 
	
	rep (i,0,n-1){
		vector<char>v; 
		rep (j,0,m-1){
			char c;cin>>c;v.pb(c); 
		}
		arr.pb(v); 
	}
	rep (i,0,m-1){
		int ok=0; 
		rep (j,0,n-1){
			if (arr[j][i] == '#') ok = 1; 
			bad[has(j,i)]=1-ok; 
		}
	}
	
	
	rep (i,0,n-1){
		rep (j,0,m-1){
			if(bad[has(i,j)]) continue; 
			rep (k,0,3){
				if (fin(i+xx[k],j+yy[k])){
					if(arr[i+xx[k]][j+yy[k]]=='#' || xx[k] == 1){
						ed[has(i,j)].pb(has(i+xx[k],j+yy[k])); 
						rev[has(i+xx[k],j+yy[k])].pb(has(i,j)); 
					}
				}
			}
		}
	}
	rep (i,0,n-1){
		rep (j,0,m-1){
			if (bad[has(i,j)]) continue; 
			if(vis[has(i,j)]) continue; 
			ori=has(i,j); 
			go (has(i,j)); 
		}
	}
	memset(vis,0,sizeof(vis)); 
	reverse(all(stck)); 
	for (int i : stck){
		if(vis[i]) continue; 
		go2 (i, i); 
	}
	rep (i,0,n-1){
		rep (j,0,m-1){
			if (bad[has(i,j)]) continue; 
			int val = has(i,j); 
			for (int k : ed[val]){
				if (scc[k] == scc[val]) continue; 
				no[scc[k]] = 1; 
			}
		}
	}
	int cnt=0; 
	rep (i,0,n-1){
		rep (j,0,m-1){
			if (bad[has(i,j)]) continue; 
			int val = has(i, j); 
			if (scc[val] == val && (!no[val])) cnt++; 
		}
	}
	cout << cnt; 
    return 0; 
}