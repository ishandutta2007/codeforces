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

const ll INF = (ll)2e18 + 6;

int n, m;
vvll v;

ll calc(ll sh){
    vvll cost(n, vll(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ll exp = sh + i + j;
            cost[i][j] = (v[i][j] < exp ? INF : v[i][j] - exp);
        }
    }
    vvll dp(n, vll(m, INF));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0){
                dp[i][j] = cost[i][j];
                continue;
            }
            dp[i][j] = min(dp[i][j], i ? dp[i-1][j] + cost[i][j] : INF);
            dp[i][j] = min(dp[i][j], j ? dp[i][j-1] + cost[i][j] : INF);
        }
    }
    return dp[n-1][m-1];
}

void solve(){
    cin >> n >> m;
    v.resize(n);
    fill(v.begin(), v.end(), vll(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    ll ans = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = min(ans, calc(v[i][j] - i - j));
        }
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