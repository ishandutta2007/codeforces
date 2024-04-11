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
    int n;
    cin >> n;
    vvi adj(1<<n);
    for(int i = 0; i < n * (1 << (n-1)); i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    debug(adj);
    vi p(1<<n, -1);
    p[0] = 0;
    set<int> used;
    used.insert(0);
    for(int i = 0; i < n; i++){
        p[1<<i] = adj[0][i];
        used.insert(adj[0][i]);
    }
    debug(used);
    for(int i = 0; i < (1<<n); i++){
        if(p[i] == -1){
            vi neigh;
            for(int b = 0; b < n; b++){
                if((i ^ (1 << b)) < i) neigh.push_back(i ^ (1 << b));
            }
            vi p_neigh;
            for(int j : neigh){
                p_neigh.push_back(p[j]);
            }
            map<int, int> cnt;
            for(int j : p_neigh){
                for(int k : adj[j]){
                    cnt[k]++;
                }
            }
            debug(i, cnt, used, p_neigh.size());
            for(auto it = cnt.begin(); it != cnt.end(); it++){
                if(it->second == p_neigh.size() && used.find(it->first) == used.end()){
                    p[i] = it->first;
                    used.insert(it->first);
                    break;
                }
            }
        }
    }
    for(int i = 0; i < (1<<n); i++){
        cout << p[i] << ' ';
    }
    cout << endl;

    if(n != 1 && n != 2 && n != 4 && n != 8 && n != 16){
        cout << -1 << endl;
    }else{
        vi pc(1<<n);
        for(int i = 0; i < (1<<n); i++){
            int c = 0;
            for(int b = 0; b < n; b++){
                if((i >> b) & 1) c ^= b;
            }
            pc[p[i]] = c;
        }
        for(int i : pc){
            cout << i << ' ';
        }
        cout << endl;
    }
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