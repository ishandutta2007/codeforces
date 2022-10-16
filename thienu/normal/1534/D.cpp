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

int n;

vi query(int v){
    cout << "? " << v+1 << endl;
    vi out(n);
    for(int i = 0; i < n; i++){
        cin >> out[i];
    }
    return out;
}

void answer(vvi adj){
    debug(adj);
    set<pii> edges;
    cout << "!" << endl;
    for(int i = 0; i < n; i++){
        for(int j : adj[i]){
            if(edges.find({i, j}) == edges.end() && edges.find({j, i}) == edges.end()){
                cout << i+1 << ' ' << j+1 << endl;
                edges.insert({i, j});
            }
        }
    }
}

void solve(){
    cin >> n;
    vi v = query(0);
    vvi depths(n);
    for(int i = 0; i < n; i++){
        depths[v[i]].push_back(i);
    }
    vvi adj(n);
    vi parity(2);
    for(int i = 0; i < n; i++){
        parity[i & 1] += depths[i].size();
    }
    debug(parity, depths);
    int start = 1;
    if(parity[0] <= parity[1]){
        start = 2;
        for(int i : depths[1]) adj[0].push_back(i);
    }
    debug(start, adj);
    for(int d = start; d < n; d+=2){
        for(int v : depths[d]){
            vi out = query(v);
            for(int i = 0; i < n; i++){
                if(out[i] == 1){
                    adj[v].push_back(i);
                }
            }
        }
    }
    answer(adj);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}