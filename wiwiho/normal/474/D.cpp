#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000000;

using namespace std;

int main(){
    StarBurstStream

    int t, k;
    cin >> t >> k;

    vector<ll> dp(100001, 1);
    for(int i = 1; i < 100001; i++){
        dp[i] = dp[i - 1];
        if(i - k >= 0) dp[i] += dp[i - k];
        dp[i] %= MOD;
    }

    //printv(dp, cerr);
    vector<ll> s(100001);
    s[0] = dp[0];
    for(int i = 1; i < 100001; i++){
        s[i] = (s[i - 1] + dp[i]) % MOD;
    }

    for(int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        cout << ((s[b] - s[a - 1] + MOD) % MOD) << "\n";
    }

    return 0;
}