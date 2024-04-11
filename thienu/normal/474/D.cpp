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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

ll MOD = 1000000007;
int MAXI = 100000;

void solve(){
    int tc, k;
    cin >> tc >> k;
    vector<ll> dp(MAXI+1);
    dp[0] = 1;
    for(int i = 1; i <= MAXI; i++){
        ll cnt = 0;
        cnt += dp[i-1];
        if(i >= k){
            cnt += dp[i-k];
        }
        cnt %= MOD;
        dp[i] = cnt;
    }
    // debug(dp);

    vector<ll> pref(MAXI+1);
    ll total = 0;
    for(int i = 0; i <= MAXI; i++){
        total = (total + dp[i]) % MOD;
        pref[i] = total;
    }

    while(tc--){
        int a, b;
        cin >> a >> b;
        cout << ((pref[b] - pref[a-1])%MOD+MOD)%MOD << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}