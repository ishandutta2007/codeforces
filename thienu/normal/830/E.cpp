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

void dfs(int u, int last, vi &vis, vi &par, vi &depth, vvi &adj, vpii &backedge, vi &comp){
    vis[u] = 1;
    comp.push_back(u);
    for(int v : adj[u]){
        if(v == last) continue;
        if(vis[v]){
            backedge.push_back({u, v});
            continue;
        }
        depth[v] = depth[u] + 1;
        par[v] = u;
        dfs(v, u, vis, par, depth, adj, backedge, comp);
    }
}

void answer_yes(vi &ans){
    cout << "YES" << endl;
    for(int i : ans){
        cout << i << ' ';
    }
    cout << endl;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    vi deg(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    if(*max_element(deg.begin(), deg.end()) >= 4){
        vi ans(n);
        int u = max_element(deg.begin(), deg.end()) - deg.begin();
        for(int i : adj[u]){
            ans[i] = 1;
        }
        ans[u] = 2;
        answer_yes(ans);
        return;
    }
    debug(1);
    
    vi vis(n), par(n, -1), depth(n);
    for(int i = 0; i < n; i++){
        debug(i);
        if(vis[i]) continue;
        vpii backedge;
        vi comp;
        depth[i] = 0;
        dfs(i, -1, vis, par, depth, adj, backedge, comp);
        if(!backedge.empty()){
            vi ans(n);
            int cur = backedge[0].first;
            for(; cur != backedge[0].second; cur = par[cur]){
                ans[cur] = 1;
            }
            ans[cur] = 1;
            answer_yes(ans);
            return;
        }
        debug(backedge);
        vi deg3;
        for(int u : comp){
            if(deg[u] >= 3) deg3.push_back(u);
        }
        if(deg3.size() >= 2){
            int u = deg3[0], v = deg3[1];
            vi ans(n);
            for(int x : adj[u]){
                ans[x] = 1;
            }
            for(int x : adj[v]){
                ans[x] = 1;
            }
            if(depth[u] > depth[v]) swap(u, v);
            while(depth[v] > depth[u]){
                ans[v] = 2;
                v = par[v];
            }
            while(v != u){
                ans[v] = 2;
                ans[u] = 2;
                v = par[v];
                u = par[u];
            }
            ans[u] = 2;
            answer_yes(ans);
            return;
        }else if(deg3.size() == 1){
            int u = deg3[0];
            vvi branches;
            vi sz;
            for(int v : adj[u]){
                vi branch;
                int cur = v, lst = u;
                branch.push_back(lst);
                branch.push_back(cur);
                while(deg[cur] == 2){
                    if(adj[cur][0] == lst){
                        lst = cur;
                        cur = adj[lst][1];
                    }else{
                        lst = cur;
                        cur = adj[lst][0];
                    }
                    branch.push_back(cur);
                }
                branches.push_back(branch);
                sz.push_back(branch.size());
            }
            debug(branches);
            ll a = sz[0], b = sz[1], c = sz[2];
            if(a * b + b * c + c * a <= a * b * c){
                for(int i = 0; i < 3; i++){
                    sz[i] = min(100, sz[i]);
                }
                vi ans(n);
                int tot = sz[0] * sz[1] * sz[2];
                ans[u] = tot;
                for(int i = 0; i < 3; i++){
                    for(int j = 1; j < sz[i]; j++){
                        ans[branches[i][j]] = tot / sz[i] * (sz[i]-j);
                    }
                }
                answer_yes(ans);
                return;
            }
        }
    }
    cout << "NO" << endl;
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