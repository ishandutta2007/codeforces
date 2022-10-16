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
    int n, p;
    cin >> n >> p;
    vi v(n);
    set<pii> vals;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        vals.insert({v[i], i});
    }
    int conn = 0;
    ll ans = 0;
    vi vis(n-1);
    while(!vals.empty()){
        int val, pos;
        tie(val, pos) = *vals.begin();
        if(val >= p) break;
        vals.erase(vals.begin());
        debug(val, pos);
        int cur = pos;
        while(cur > 0 && !vis[cur-1] && v[cur-1] % v[pos] == 0){
            cur--;
            ans += v[pos];
            conn++;
            vis[cur] = 1;
        }
        cur = pos;
        while(cur + 1 < n && !vis[cur] && v[cur+1] % v[pos] == 0){
            vis[cur] = 1;
            cur++;
            ans += v[pos];
            conn++;
        }
    }
    ans += 1LL * (n-1-conn) * p;
    debug(ans, vis, conn);
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