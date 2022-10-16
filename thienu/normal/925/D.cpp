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

const int INF = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    debug(adj);
    vi bfs_dist(n, INF);
    vi bfs_par(n, -1);
    queue<int> q;
    q.push(0);
    bfs_dist[0] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(bfs_dist[v] != INF) continue;
            bfs_dist[v] = bfs_dist[u] + 1;
            q.push(v);
            bfs_par[v] = u;
        }
    }
    debug(bfs_dist, bfs_par);

    if(bfs_dist[n-1] <= 4){
        vi v = {n-1};
        int cur = n-1;
        while(cur != 0){
            cur = bfs_par[cur];
            v.push_back(cur);
        }
        reverse(v.begin(), v.end());
        cout << bfs_dist[n-1] << endl;
        for(int i : v){
            cout << i+1 << ' ';
        }
        cout << endl;
        return;
    }
    int two = -1;
    for(int i = 0; i < n; i++){
        if(bfs_dist[i] == 2){
            two = i;
        }
    }
    debug(two);
    if(two != -1){
        cout << 4 << endl << "1 " << bfs_par[two] + 1 << ' ' << two+1 << " 1 " << n << endl;
        return;
    }
    
    vi vis(n);
    vi dist(n, -1);
    vi par(n, -1);
    vi degree(n);
    vis[0] = 1;
    for(int u : adj[0]){
        debug(u);
        if(vis[u]) continue;
        set<int> comp;
        comp.insert(u);
        vis[u] = 1;
        queue<int> q;
        q.push(u);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int x : adj[v]){
                if(vis[x]) continue;
                comp.insert(x);
                vis[x] = 1;
                q.push(x);
            }
        }
        debug(comp);
        int start = -1;
        for(int i : comp){
            for(int j : adj[i]){
                if(comp.find(j) != comp.end()){
                    degree[i]++;
                }
            }
            if(degree[i] < (int) comp.size() - 1){
                start = i;
                break;
            }
        }
        debug(comp, start);
        if(start == -1) continue;
        q.push(start);
        dist[start] = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int x : adj[v]){
                if(comp.find(x) == comp.end() || dist[x] != -1) continue;
                dist[x] = dist[v] + 1;
                q.push(x);
                par[x] = v;
            }
        }
        int two2 = -1;
        for(int i : comp){
            if(dist[i] == 2){
                two2 = i;
            }
        }
        cout << 5 << endl << "1 " << start+1 << ' ' << par[two2] + 1 << ' ' << two2+1 << ' ' << start+1 << ' ' << n << endl;
        return;
    }
    cout << -1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}