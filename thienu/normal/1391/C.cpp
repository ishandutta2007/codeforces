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

ll MOD = 1e9 + 7;

ll factorials[1000005];

ll inverse(ll x){
    // x^(MOD-2)
    ll pow = MOD-2;
    ll ans = 1;
    while(pow){
        if(pow & 1){
            ans = (ans * x) % MOD;
        }
        x = (x * x) % MOD;
        pow >>= 1;
    }
    return ans;
}

ll ncr(ll n, ll r){
    return factorials[n] * inverse(factorials[r]) % MOD * inverse(factorials[n-r]) % MOD;
}

void solve(){
    int n;
    cin >> n;
    ll ans = factorials[n];

    // place max at i
    for(int i = 0; i < n; i++){
        ans = ((ans - ncr(n-1, i) % MOD) + MOD) % MOD;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    factorials[0] = 1;
    for(int i = 1; i < 1000005; i++) factorials[i] = (factorials[i-1] * i) % MOD;

    solve();
    return 0;
}