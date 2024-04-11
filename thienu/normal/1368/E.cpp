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

int depth(int v, vector<vector<int>> &parent, vector<int> &depths){
    if(depths[v] != -1) return depths[v];
    int ans = 0;
    for(int u : parent[v]){
        int res = depth(u, parent, depths);
        ans = max(ans, (res + 1) % 3);
    }
    depths[v] = ans;
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    // vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> parent(n, vector<int>());
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        // adj[x].push_back(y);
        parent[y].push_back(x);
    }
    debug(parent);
    set<int> ans;
    
    vector<int> depths(n, -1);

    for(int i = 0; i < n; i++){
        if(depth(i, parent, depths) == 2){
            ans.insert(i);
        }
    }

    cout << ans.size() << endl;
    for(int i : ans){
        cout << i+1 << " ";
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