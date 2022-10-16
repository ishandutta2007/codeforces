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

ll INF = 1e10 + 69;

ll calc_depth(ll cyc, ll k){
    cyc %= 2 * k;
    if(cyc < k){
        return k - cyc;
    }
    else{
        return cyc - k;
    }
}

void solve(){
    int n;
    ll k, l;
    cin >> n >> k >> l;
    vll v(n+2);
    for(int i = 1; i <= n; i++) cin >> v[i];
    v[0] = -INF;
    v[n+1] = -INF;
    ll cyc = 0; // cycle: k k-1 k-2 ... 0 ... k-1
    int cur = 0;
    while(cur <= n){
        cyc %= 2 * k;
        debug(cur, cyc);
        if(v[cur] + k <= l){
            cyc = 0;
            debug("reset");
        }
        debug(k, l - v[cur + 1]);
        ll max_nxt_depth = min(k, l - v[cur + 1]);
        if(max_nxt_depth < 0){
            cout << "No" << endl;
            return;
        }
        ll min_nxt_cycle = k - max_nxt_depth;
        ll nxt = max(min_nxt_cycle, cyc + 1);
        debug(nxt, min_nxt_cycle, max_nxt_depth);
        int nxt_depth = calc_depth(nxt, k);
        int cur_depth = calc_depth(nxt-1, k);
        debug(nxt_depth, cur_depth);
        if(v[cur] + cur_depth > l || v[cur+1] + nxt_depth > l){
            cout << "No" << endl;
            return;
        }
        cyc = nxt;
        cur++;
    }
    cout << "Yes" << endl;
    return;
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