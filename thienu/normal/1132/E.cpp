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
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

// looked at half of editorial

ll L = 840;
void solve(){
    ll n;
    cin >> n;
    vector<ll> v(8);
    for(int i = 0; i < 8; i++) cin >> v[i];
    // dp[i][j] is maximum number of L-groups with extra weight j after pile i-1
    vector<vector<ll>> dp(9, vector<ll>(10*L, -1));
    dp[0][0] = 0;
    for(ll i = 0; i < 8; i++){
        for(ll j = 0; j < L/(i+1); j++){
            if(v[i] < j) continue;
            ll weight = j * (i+1);
            ll extra = (v[i] - j) * (i+1) / L;
            for(ll k = 0; k < 9 * L - weight; k++){
                // debug(dp[i][k]);
                if(dp[i][k] != -1){
                    debug(i+1, k+weight, dp[i][k] + extra * L, dp[8][456]);
                    dp[i+1][k+weight] = max(dp[i+1][k+weight], dp[i][k] + extra);
                }
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < 10 * L; i++){
        if(i > n) continue;
        if(dp[8][i] == -1) continue;
        if(i == 456){
            debug(i);
        }
        ll num_l_groups = (n - i) / L;
        ans = max(ans, min(num_l_groups, dp[8][i]) * L + i);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}