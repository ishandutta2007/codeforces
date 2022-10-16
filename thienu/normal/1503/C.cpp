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

ll INF = 1e18;

void st_set(vll &st, int tl, int tr, int pos, int index, ll value){
    // debug("set", tl, tr);
    if(tl == tr){
        // debug("set", pos, index, tl, value);
        st[pos] = value;
        return;
    }
    // debug(tl + (tr - tl) / 2, index, tl + (tr - tl) / 2 <= index);
    if(index <= tl + (tr - tl) / 2){
        st_set(st, tl, tl + (tr - tl) / 2, pos * 2, index, value);
    }
    else{
        st_set(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, index, value);
    }
    st[pos] = min(st[pos * 2], st[pos * 2 + 1]);
}

ll st_min(vll &st, int tl, int tr, int pos, int left, int right){
    if(right < tl || tr < left) return INF;
    // debug(tl, tr, left, right, pos);
    if(left <= tl && tr <= right){
        debug(tl, tr, left, right, pos, st[pos]);
        return st[pos];
    }
    ll a = st_min(st, tl, tl + (tr - tl) / 2, pos * 2, left, right);
    ll b = st_min(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right);
    // debug(tl, tr, left, right, a, b);
    return min(a, b);
}

void solve(){
    int n;
    cin >> n;
    vpii cities(n); // (a, c)
    ll csum = 0;
    for(int i = 0; i < n; i++){
        int a, c;
        cin >> a >> c;
        cities[i] = {a, c};
        csum += c;
    }
    
    sort(cities.begin(), cities.end());
    
    vi beauty(n);
    for(int i = 0; i < n; i++){
        beauty[i] = cities[i].first;
    }

    vll st(4 * n, INF);
    vll dp(n);
    dp[n-1] = 0;
    st_set(st, 0, n-1, 1, n-1, 0);

    debug(cities);
    
    for(int i = n-2; i >= 0; i--){
        // if(i % 100 == 0) cout << i << endl;
        int threshold = distance(beauty.begin(), prev(upper_bound(beauty.begin(), beauty.end(), cities[i].first + cities[i].second)));
        // int threshold = prev(upper_bound(beauty.begin(), beauty.end(), cities[i].first + cities[i].second)) - beauty.begin();
        debug(i, dp, threshold);
        if(threshold < n-1){
            dp[i] = dp[threshold+1] + cities[threshold+1].first - cities[i].first - cities[i].second;
        }
        if(threshold > i){
            debug(st_min(st, 0, n-1, 1, i+1, threshold));
            dp[i] = min(dp[i], st_min(st, 0, n-1, 1, i+1, threshold));
        }
        st_set(st, 0, n-1, 1, i, dp[i]);
        debug(st);
    }

    cout << csum + dp[0] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}