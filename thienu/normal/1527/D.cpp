#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

// kactl
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi time, path, ret;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

void dfs(int u, int last, vi &size, vi &branch, vvi &adj){
    int s = 1;
    for(int v : adj[u]){
        if(v == last) continue;
        if(u == 0){
            branch[v] = v;
        }else{
            branch[v] = branch[u];
        }
        dfs(v, u, size, branch, adj);
        s += size[v];
    }
    size[u] = s;
}

void solve(){
    int n;
    cin >> n;
    vvi adj(n);

    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // paths[i] = num paths that pass through 0..i-1 (paths[0] is all paths)
    vll paths(n+2);
    paths[0] = 1LL * n * (n-1) / 2;
    LCA lca(adj);
    vi size(n), branch(n);
    dfs(0, -1, size, branch, adj);
    debug(size);
    // paths[1]
    ll s = 0;
    ll sq = 0;
    for(int v : adj[0]){
        s += size[v];
        sq += 1LL * size[v] * size[v];
    }
    paths[1] = s + (s * s - sq) / 2LL;
    debug(paths);
    
    int p1 = 0, p2 = 0;
    for(int i = 1; i < n; i++){
        int l1 = lca.lca(p1, i);
        int l2 = lca.lca(p2, i);
        debug(i, p1, p2, l1, l2);
        if(l1 == p1){
            p1 = i;
        }else if(l1 == i){}
        else if(p1 != 0 && branch[i] == branch[p1]) break;
        else if(l2 == p2){
            p2 = i;
        }else if(l2 == i){}
        else break;

        if(p2 == 0){
            paths[i+1] = 1LL * (n-size[branch[p1]]) * size[p1];
        }else{
            paths[i+1] = 1LL * size[p1] * size[p2];
        }
    }
    debug(paths);
    for(int i = 0; i <= n; i++){
        cout << paths[i] - paths[i+1] << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}