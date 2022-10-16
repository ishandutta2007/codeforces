#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;

using namespace std;

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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif



vector<int> color;
vector<int> parent;
vector<int> depths;
int cycle_start, cycle_end;
int start_depth = -1;

bool dfs(int v, vector<vector<int>> &adj, int prev, int depth) {
    debug(v, color, depths);
    color[v] = 1;
    depths[v] = depth;
    bool ok = false;
    for (int u : adj[v]) {
        if(u == prev) continue;
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u, adj, v, depth+1))
                ok = true;
        } else if (color[u] == 1) {
            debug(u);
            if(depths[u] > start_depth){
                cycle_end = v;
                cycle_start = u;
            }
            ok = true;
        }
    }
    color[v] = 2;
    return ok;
}

vector<int> find_cycle(int n, vector<vector<int>> &adj) {
    color.assign(n, 0);
    parent.assign(n, -1);
    depths.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v, adj, -1, 0))
            break;
    }

    if (cycle_start == -1) {
        return vector<int>();
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        return cycle;
    }
}


void dfs_tree(int v, int prev, vector<vector<int>> &adj, vector<int> &red, vector<int> &blue, bool is_red){
    if(is_red){
        red.push_back(v);
    }
    else{
        blue.push_back(v);
    }
    for(int i : adj[v]){
        if(i == prev) continue;
        dfs_tree(i, v, adj, red, blue, !is_red);
    }
}


void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> cycle = find_cycle(n, adj);
    debug(cycle);

    if(cycle.size() == 0){
        vector<int> red;
        vector<int> blue;
        dfs_tree(0, -1, adj, red, blue, true);
        if(red.size() >= (k+1)/2){
            cout << 1 << endl;
            for(int i = 0; i < (k+1)/2; i++){
                cout << red[i] + 1 << " ";
            }
            cout << endl;
        }
        else{
            cout << 1 << endl;
            for(int i = 0; i < (k+1)/2; i++){
                cout << blue[i] + 1 << " ";
            }
            cout << endl;
        }
    }
    else if(cycle.size() <= k+1){
        cout << 2 << endl;
        cout << cycle.size() - 1 << endl;
        for(int i = 0; i < cycle.size()-1; i++){
            cout << cycle[i] + 1 << " ";
        }
        cout << endl;
    }
    else{
        cout << 1 << endl;
        for(int i = 0; i < (k+1)/2; i++){
            cout << cycle[2 * i] + 1 << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}