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

int find_set(int v, vi &parent){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v], parent);
}

void solve(){
    int n;
    cin >> n;
    vi v(n);
    int next = 0;
    vi parent(n);
    for(int i = 0; i < n; i++) parent[i] = i;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] == 1 && next == i) next++;
        if(i + 1 <= n-1 && v[i] == 1 && v[i+1] == 1){
            parent[i] = find_set(i+1, parent);
        }
        if(i > 0 && v[i] == 1 && v[i-1] == 1){
            parent[i-1] = parent[i];
        }
    }
    debug(parent);
    ll ans = 0;
    while(next < n){
        debug(next, v);
        if(v[next] > n){
            ans += v[next] - n;
            v[next] = n;
        }
        if(v[next] == 1){
            next++;
            continue;
        }
        int cur = next;
        while(cur < n){
            if(v[cur] == 1){
                cur = find_set(cur, parent) + 1;
                continue;
            }
            int t = cur;
            cur = cur + v[cur];
            v[t] = max(v[t] - 1, 1);
            if(t + 1 <= n-1 && v[t] == 1 && v[t+1] == 1){
                parent[t] = find_set(t+1, parent);
            }
            if(t > 0 && v[t] == 1 && v[t-1] == 1){
                parent[t-1] = parent[t];
            }
        }
        ans++;
    }
    cout << ans << endl;
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