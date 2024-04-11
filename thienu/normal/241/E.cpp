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

void solve(){
    int n, m;
    cin >> n >> m;
    vvi adj(n); // cap = 2
    vvi radj(n); // cap = -1
    vpii edges;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        radj[y].push_back(x);
        edges.push_back({x, y});
    }
    vi vis1(n), vis2(n);
    queue<int> q;
    q.push(0);
    vis1[0] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(!vis1[v]){
                vis1[v] = 1;
                q.push(v);
            }
        }
    }
    q.push(n-1);
    vis2[n-1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : radj[u]){
            if(!vis2[v]){
                vis2[v] = 1;
                q.push(v);
            }
        }
    }

    debug(vis1, vis2);
    
    vi d(n);
    for(int iter = 0; iter <= n; iter++){
        bool f = false;
        for(int i = 0; i < n; i++){
            for(int j : adj[i]){
                if(vis1[i] && vis1[j] && vis2[i] && vis2[j] && d[i] + 2 < d[j]){
                    debug(i, j, "for");
                    d[j] = d[i] + 2;
                    f = true;
                }
            }
            for(int j : radj[i]){
                if(vis1[i] && vis1[j] && vis2[i] && vis2[j] && d[i] - 1 < d[j]){
                    debug(i, j, "rev");
                    d[j] = d[i] - 1;
                    f = true;
                }
            }
        }
        debug(iter, d);
        if(iter == n && f){
            cout << "No" << endl;
            return;
        }
    }
    debug(d);
    cout << "Yes" << '\n';
    for(pii p : edges){
        cout << min(2, max(1, d[p.second]-d[p.first])) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}