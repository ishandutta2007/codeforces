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

int INF = 2e9 + 7;

int find_set(int v, vi &parent){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(int a, int b, vi &parent, vi &size){
    a = find_set(a, parent);
    b = find_set(b, parent);
    if(a != b){
        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

void union_sets2(int a, int b, vi &parent, vi &size, vi &good){
    a = find_set(a, parent);
    b = find_set(b, parent);
    if(a != b){
        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        good[a] = max(good[a], good[b]);
    }
}

ll MOD = 1e9 + 7;

ll binpow(ll a, ll b, ll m){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> queries;

    vector<vpii> adj(m); // index, to


    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x == 1){
            int y;
            cin >> y;
            y--;
            queries.push_back({y});
        }
        else{
            int y, z;
            cin >> y >> z;
            y--;
            z--;
            queries.push_back({y, z});
        }
    }

    vi ans;

    debug("reached dsu2");
    debug(queries);

    // dsu 2 electric boogaloo
    vi parent2(m);
    for(int i = 0; i < m; i++) parent2[i] = i;
    vi good(m, 0);
    vi size2(m, 1);
    for(int i = 0; i < n; i++){
        vi v = queries[i];
        if(v.size() == 1){
            if(!good[find_set(v[0], parent2)]){
                ans.push_back(i+1);
                good[find_set(v[0], parent2)] = 1;
            }
        }
        else if(v.size() == 2){
            if(find_set(v[0], parent2) != find_set(v[1], parent2) && !(good[find_set(v[0], parent2)] && good[find_set(v[1], parent2)])){
                ans.push_back(i+1);
                union_sets2(v[0], v[1], parent2, size2, good);
            }
        }
    }

    int pow = 0;

    for(int i = 0; i < m; i++){
        if(parent2[i] == i){
            pow += size2[i];
            if(!good[i]) pow -= 1;
        }
    }

    debug(pow, ans);

    cout << binpow(2, pow, MOD) << " " << ans.size() << endl;
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;

    debug(binpow(2, 32, MOD));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}