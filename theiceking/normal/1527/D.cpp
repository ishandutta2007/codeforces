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
 
const int maxn = (int)2e5 + 505;
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

vector <int> edges [maxn];
int pa [maxn][21]; 
int depth[maxn]; 
int sub [maxn]; 
void go (int node, int p = 0){
	pa[node][0] = p; depth[node] = depth[p] +  1; sub[node] = 1; 
	for (int i : edges[node]){
		if(i==p)continue;
		go(i,node); 
		sub[node]+=sub[i]; 
	}
}
int lca (int a, int b){
	if(a==b)return a; 
	if(depth[a]>depth[b])swap(a,b);
	int val = depth[b]-depth[a]; 
	repr (i, 20, 0){
		if ((1<<i)&val)b=pa[b][i] ;
	}
	if(a==b)return a; 
	repr (i, 20, 0){
		if (pa[a][i]==pa[b][i]) continue; 
		a=pa[a][i];b=pa[b][i]; 
	}
	return pa[a][0]; 
}
int get_pa (int a, int v){
	if(v==0)return a; 
	rep (i, 0, 20){
		if ((1<<i)&v) a = pa[a][i]; 
	}
	return a; 
}
int num_paths [maxn]; 

bool on_path (int a, int b, int c){
	int lc = lca(a, b); 
	if (depth[c] >= depth[lc] && depth[c] <= depth[a]){
		if (get_pa (a, depth[a] - depth[c]) == c) return 1; 
	}
	if (depth[c] >= depth[lc] && depth[c] <= depth[b]){
		if (get_pa (b, depth[b] - depth[c]) == c) return 1; 
	}
	return 0; 
}
main(){
    cin.tie(0); ios_base::sync_with_stdio(0); 
	
	int tc; cin >> tc; 
	rep (tt, 1, tc){
		int n; cin >> n; 
		
		rep (i, 1, n - 1){
			int u, v; cin >> u >> v; 
			u++;v++; 
			edges[u].pb(v);edges[v].pb(u); 
		}
		go (1); 
		
		rep (i, 1, 20){
			rep(j, 1, n) pa[j][i] = pa[pa[j][i-1]][i-1];
		}
		
		int cur_s = 1, cur_e = 1;
		int tot =  0; 
		for(int i : edges[1]){
			num_paths[1] += sub[i] * tot;  
			tot += sub[i]; 
		}
		num_paths[1] += n - 1; 
		
		int tz = n - sub[(get_pa (2, depth[2] - depth[1] - 1))];
		
		rep (i, 2, n){
			if (on_path (cur_s, cur_e, i)){
				num_paths[i] = num_paths[i - 1]; continue; 
			}
			int path = depth[cur_s] + depth[cur_e] - 2 * depth[lca(cur_s, cur_e)];
			
			int lc  = lca(i, cur_s); 
			int dist1 = depth[i] + depth[cur_s] - 2 * depth[lc]; 
			lc = lca(i, cur_e); 
			int dist2 = depth[i] + depth[cur_e] - 2 * depth[lc]; 
			
			if (dist1 > dist2){
				swap(cur_s, cur_e); 
				swap(dist1, dist2); 
			}
			if (path + dist1 != dist2) break; 
			cur_s = i;
			if (depth[cur_e] < depth[cur_s]) swap(cur_e, cur_s); 
			if (get_pa(cur_e, depth[cur_e] - depth[cur_s]) == cur_s){
				num_paths[i] = tz * sub[cur_e]; 
			}
			else{
				num_paths[i] = sub[cur_s] * sub[cur_e]; 
			}
			
		}
		int la = (n * (n - 1)) / 2; 
		rep (i, 1, n + 1){
			cout << la  - num_paths[i] << ' '; 
			la = num_paths[i]; 
		}
		cout  << '\n'; 
		rep (i, 0, n + 5) {num_paths[i] = 0; edges[i].clear(); }
	}
    return 0; 
}