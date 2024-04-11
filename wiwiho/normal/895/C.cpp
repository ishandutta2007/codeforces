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
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<int> prime;

vector<ll> f;

ll inv(ll a){
    ll b = MOD - 2;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

ll C(ll n, ll k){
    if(n < k) return 0;
    return f[n] * inv(f[k]) % MOD * inv(f[n - k]) % MOD;
}

signed main(){
    StarBurstStream

    for(int i = 2; i <= 70; i++){
        bool ok = true;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                ok = false;
                break;
            }
        }
        if(ok) prime.eb(i);
    }
    int m = prime.size();

    f.resize(100001);
    f[0] = 1;
    for(int i = 1; i <= 100000; i++) f[i] = f[i - 1] * i % MOD;

    int n;
    cin >> n;
    vector<int> cnt(71);
    while(n--){
        int a;
        cin >> a;
        cnt[a]++;
    }

    vector<ll> dp(1 << m);
    dp[0] = 1;
    for(int i = 1; i <= 70; i++){
        int ii = i;
        int now = 0;
        for(int j = 0; j < m; j++){
            while(ii % prime[j] == 0){
                ii /= prime[j];
                now ^= 1 << j;
            }
        }

        ll t1 = 0, t0 = 1;
        for(int j = 1; j <= cnt[i]; j += 2){
            t1 += C(cnt[i], j);
            t1 %= MOD;
        }
        for(int j = 2; j <= cnt[i]; j += 2){
            t0 += C(cnt[i], j);
            t0 %= MOD;
        }


        vector<ll> dp2(1 << m);
        for(int j = 0; j < (1 << m); j++){
            dp2[j ^ now] += dp[j] * t1 % MOD;
            dp2[j ^ now] %= MOD;
            dp2[j] += dp[j] * t0 % MOD;
            dp2[j] %= MOD;
        }
        dp = dp2;
    }
    cout << dp[0] - 1 << "\n";

    return 0;
}