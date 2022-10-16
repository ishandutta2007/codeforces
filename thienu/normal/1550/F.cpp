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
const ll LLINF = 1e18;

vi parent;
vvi comps;

set<int> active;

void merge(int a, int b){
    a = parent[a], b = parent[b];
    if(a == b) return;
    if(comps[a].size() < comps[b].size()) swap(a, b);
    for(int i : comps[b]){
        parent[i] = a;
        comps[a].push_back(i);
    }
    comps[b].clear();
    active.erase(b);
    return;
}

ll hash_edge(ll a, ll b){
    return (max(a, b) << 32) | min(a, b);
}

void solve(){
    int n, q, s, d;
    cin >> n >> q >> s >> d;
    s--;
    vi v(n);
    set<pii> pos;

    parent.resize(n);
    comps.resize(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
        parent[i] = i;
        comps[i] = {i};
        active.insert(i);
        pos.insert({v[i], i});
    }
    // spanning tree
    vector<set<pii>> adj(n);
    
    while(active.size() > 1){
        debug(active);
        vpii to_merge;
        for(int p : active){
            pair<int, ll> best = {INF, LLINF};
            int orig = -1;
            int to = -1;
            for(int i : comps[p]){
                pos.erase({v[i], i});
            }
            for(int i : comps[p]){
                vi cand;
                auto it = pos.upper_bound({v[i]+d, -1});
                if(it != pos.end()) cand.push_back(it->second);
                if(it != pos.begin()) it--; cand.push_back(it->second);

                it = pos.upper_bound({v[i]-d, -1});
                if(it != pos.end()) cand.push_back(it->second);
                if(it != pos.begin()) it--; cand.push_back(it->second);

                debug(p, i, cand);

                for(int j : cand){
                    int dist = abs(d-abs(v[j]-v[i]));
                    pair<int, ll> x = {dist, hash_edge(v[j], v[i])};
                    if(x < best){
                        best = x;
                        orig = i;
                        to = j;
                    }
                }
            }
            adj[orig].insert({to, best.first});
            adj[to].insert({orig, best.first});
            to_merge.push_back({orig, to});
            
            for(int i : comps[p]){
                pos.insert({v[i], i});
            }
        }
        for(pii p : to_merge){
            merge(p.first, p.second);
        }
    }
    debug(adj);

    vi min_k(n, -1);
    queue<int> qu;
    qu.push(s);
    min_k[s] = 0;
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for(pii p : adj[u]){
            int dest, cost;
            tie(dest, cost) = p;
            if(min_k[dest] != -1) continue;
            min_k[dest] = max(min_k[u], cost);
            qu.push(dest);
        }
    }

    while(q--){
        int i, k;
        cin >> i >> k;
        i--;
        if(min_k[i] <= k){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}