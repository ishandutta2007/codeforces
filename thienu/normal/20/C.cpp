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

ll INF = 1e18 + 7;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    for(int i = 0; i < m; i++){
        int a, b, x;
        cin >> a >> b >> x;
        a--;
        b--;
        adj[a].push_back({b, x});
        adj[b].push_back({a, x});
    }
    vector<ll> dist(n, INF);
    dist[0] = 0LL;

    vector<int> bef(n, -1);

    set<pair<ll, int>> q;
    q.insert(make_pair(0, 0));
    
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());

        for(auto edge : adj[v]){
            int u = edge.first;
            int w = edge.second;

            if(dist[v] + w < dist[u]){
                q.erase({dist[u], u});
                dist[u] = dist[v] + w;
                bef[u] = v;
                q.insert(make_pair(dist[u], u));
            } 
        }
    }

    debug(dist, bef);

    if(dist[n-1] == INF){
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    int u = n-1;
    while(u != 0){
        ans.push_back(u);
        u = bef[u];
    }
    ans.push_back(0);
    reverse(ans.begin(), ans.end());

    for(int i : ans){
        cout << i+1 << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}