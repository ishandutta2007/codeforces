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
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)
#define iceil(a) ((int)ceil((int)a))
#define ifloor(a) ((int)floor((int)a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> s(n + 1);
    for(int i = 1; i <= n; i++){
        s[i] = s[i - 1] + a[i];
    }

    ll ans = 0;
    vector<ll> dp(n + 1);
    for(int i = m; i <= n; i++){
        dp[i] = max(0LL, dp[i - m] + s[i] - s[i -  m] - k);
    }

    for(int i = 0; i <= n; i++){
        ll now = dp[i];
        ans = max(ans, now);
        //cerr << now << " ";
        now -= k;
        for(int j = 1; j <= m && i + j <= n; j++){
            now += a[i + j];
            //cerr << now << " ";
            ans = max(ans, now);
        }
        //cerr << "\n";
    }

    cout << ans << "\n";

    return 0;
}