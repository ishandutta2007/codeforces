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
 
const int maxn = (int)2e5 + 305;
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
 
int  v[maxn], t [maxn], vis[maxn], col[maxn]; 
vector <int> ed [maxn]; 
 
vector<int>comp; 
 
void go (int  node, int cur){
	col[node]=cur; 
	vis[node]=1; 
	comp.pb(node); 
	for (int  i : ed[node]){
		if (vis[i]) continue; go(i, cur^1); 
	}
}
void go2 (int node,  int pa=0){
	vis[node]=1; 
	for (int i : ed[node]){
		if (vis[i]) continue; 
		go2(i, node); 
	}
	if(pa!=0){
		int diff = t[node]-v[node]; 
		v[node]+=diff;
		v[pa]+=diff; 
	}
}
main(){
    cin.tie(0); ios_base::sync_with_stdio(0); 
	int tc;  cin >> tc;
	rep (tt, 1,  tc){

		int n, m; cin >> n >> m; 
		rep (i,0,n+5){
			v[i]=t[i]=vis[i]=col[i]=0; 
			ed[i].clear(); 
		}
		int s1=0,s2=0; 
		rep (i,1,n) cin >> v[i] ;
		rep (i,1,n) cin >> t[i]; 
		rep (i,1,n){
		    s1+=v[i]; s2+=t[i]; 
		}
		
		rep (i,1,m){
			int a,b;cin>>a>>b;
			ed[a].pb(b); 
			ed[b].pb(a); 
		}
		if ((s1&1)!=(s2&1)){
		    cout << "NO\n"; continue; 
		}
		int bad=0; 
		rep (i,1,n){
			if(vis[i]) continue; 
			comp.clear(); 
			go(i, 0); 
			int ok=0; 
			for (int j : comp){
				for (int k : ed[j]){
					if (col[j]==col[k]) ok=1; 
				}
			}
			if(ok) continue; 
			for (int j : comp) vis[j]=0; 
			go2(i); 
			if (t[i]!=v[i]) {bad=1; break;}
			for (int j : comp) vis[j]=1; 
		}
		if(bad)cout<<"NO" << '\n'; 
		else cout <<"YES" << '\n'; 
 
	}
    return 0; 
}