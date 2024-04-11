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

int add(int a, int b){
    if(min(a, b) == -1) return -1;
    return min(2, a+b);
}

void dfs1(int u, vvi &adj, vi &order, vi &vis){
    vis[u] = 1;
    for(int v : adj[u]){
        if(vis[v]) continue;
        dfs1(v, adj, order, vis);
    }
    order.push_back(u);
}

void dfs2(int u, vvi &radj, vi &comp_num, vi &comp){
    for(int v : radj[u]){
        if(comp_num[v] != -1) continue;
        comp_num[v] = comp_num[u];
        comp.push_back(v);
        dfs2(v, radj, comp_num, comp);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    vvi radj(n);
    vi self_loop(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        if(x == y) self_loop[x] = 1;
        else{
            adj[x].push_back(y);
            radj[y].push_back(x);
        }
    }
    vi order;
    vi vis(n);
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        dfs1(i, adj, order, vis);
    }
    debug(order, vis);
    reverse(order.begin(), order.end());
    int ccnt = 0;
    vi comp_num(n, -1);
    vvi comps;
    for(int i : order){
        if(comp_num[i] != -1) continue;
        vi comp = {i};
        comp_num[i] = ccnt;
        dfs2(i, radj, comp_num, comp);
        comps.push_back(comp);
        ccnt++;
    }
    debug(comp_num, comps);

    // vector<set<int>> cadj(ccnt);
    vector<set<int>> rcadj(ccnt);
    for(int i = 0; i < n; i++){
        for(int j : adj[i]){
            if(comp_num[i] == comp_num[j]) continue;
            rcadj[comp_num[j]].insert(comp_num[i]);
        }
    }
    
    vi loop(ccnt);
    for(int i = 0; i < ccnt; i++){
        loop[i] = (comps[i].size() > 1 || self_loop[comps[i][0]]);
    }

    debug(loop);
    debug(rcadj);

    vi ans(ccnt);
    for(int i = 0; i < ccnt; i++){
        if(i == comp_num[0]){
            ans[i] = loop[i] ? -1 : 1;
            continue;
        }
        for(int j : rcadj[i]){
            ans[i] = add(ans[j], ans[i]);
        }
        if(ans[i] > 0 && loop[i]) ans[i] = -1;
    }
    debug(ans);
    for(int i = 0; i < n; i++){
        cout << ans[comp_num[i]] << ' ';
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