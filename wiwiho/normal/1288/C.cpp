//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define B back()
#define FR front()
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    for(int i = 1; i <= n; i++) dp[i][1] = 1;
    for(int i = 1; i <= m; i++) dp[1][i] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            dp[i][j] = 0;
            for(int k = 1; k <= i; k++){
                dp[i][j] += dp[k][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }
    //for(int i = 1; i <= n; i++) printv(dp[i], cerr);

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            ans += dp[i][m] * dp[n - j + 1][m] % MOD;
            //cerr << i << " " << n - j + 1 << "\n";
            ans %= MOD;
        }
    }

    cout << ans << "\n";

    return 0;
}