//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a + b - 1) / b)
#define tomax(a, b) (a = max(a, b))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 998244353;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll fp(ll a, ll b){
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

ll inv(ll a){
    ll b = MOD - 2;
    return fp(a, b);
}

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    dp[1][1] = 2;
    for(int i = 1; i < n; i++){
        vector<vector<ll>> dp1(n + 1, vector<ll>(n + 1));
        for(int j = 1; j <= i; j++){
            for(int l = 1; l <= i; l++){
                dp1[1][l] += dp[j][l];
                dp1[1][l] %= MOD;
                dp1[j + 1][max(l, j + 1)] += dp[j][l];
                dp1[j + 1][max(l, j + 1)] %= MOD;
            }
        }
        dp = dp1;
    }

    vector<ll> cnt(n + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cnt[j] += dp[i][j];
            cnt[j] %= MOD;
        }
    }
//    printv(cnt, cerr);

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i * j >= k) continue;
            ans += cnt[i] * cnt[j];
            ans %= MOD;
        }
    }

    cout << ans * inv(2) % MOD << "\n";

    return 0;
}