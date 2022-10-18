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
vector<ll> f;

ll C(ll n, ll k){
    assert(n >= k);
    return f[n] * inv(f[k]) % MOD * inv(f[n - k]) % MOD;
}

int main(){
    StarBurstStream

    int n, p;
    cin >> n >> p;

    vector<int> c(n + 1);
    for(int i = 1; i <= n; i++) cin >> c[i];

    f.resize(n + 1);
    f[0] = 1;
    for(int i = 1; i <= n; i++) f[i] = f[i - 1] * i % MOD;

    vector<ll> ceven(n + 1), codd(n + 1);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(j % 2) codd[i] += C(i, j), codd[i] %= MOD;
            else ceven[i] += C(i, j), ceven[i] %= MOD;
        }
    }

    vector<ll> two(1001);
    two[0] = 1;
    for(int i = 1; i <= 1000; i++) two[i] = two[i - 1] * 2 % MOD;

    vector<vector<vector<vector<ll>>>> dp(n + 1, vector<vector<vector<ll>>>(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1))));
    dp[0][0][0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int ow = 0; ow <= n; ow++){
            for(int ew = 0; ew <= n; ew++){
                for(int ob = 0; ob <= n; ob++){
                    if(ow + ew + ob > i) break;
                    int eb = i - ow - ew - ob;
                    if(c[i] == -1 || c[i] == 1){
                        if(ow) dp[i][ow][ew][ob] += two[ow + ew + eb - 1] * dp[i - 1][ow - 1][ew][ob] % MOD * ceven[ob] % MOD;
                        if(ew) dp[i][ow][ew][ob] += two[ow + ew + eb - 1] * dp[i - 1][ow][ew - 1][ob] % MOD * codd[ob] % MOD;
                        dp[i][ow][ew][ob] %= MOD;
                    }
                    if(c[i] == -1 || c[i] == 0){
                        if(ob) dp[i][ow][ew][ob] += two[ob + eb + ew - 1] * dp[i - 1][ow][ew][ob - 1] % MOD * ceven[ow] % MOD;
                        if(eb) dp[i][ow][ew][ob] += two[ob + eb + ew - 1] * dp[i - 1][ow][ew][ob] % MOD * codd[ow] % MOD;
                        dp[i][ow][ew][ob] %= MOD;
                    }
//                    cerr << "test " << i << " " << ow << " " << ew << " " << ob << " " << eb << " " << dp[i][ow][ew][ob] << "\n";
                }
            }
        }
    }

    ll ans = 0;
    for(int ow = 0; ow <= n; ow++){
        for(int ew = 0; ew <= n; ew++){
            for(int ob = 0; ob <= n; ob++){
                int eb = n - ow - ew - ob;
                if(eb < 0) continue;
                if((ow + ob) % 2 == p){
                    ans += dp[n][ow][ew][ob];
                    ans %= MOD;
                }
            }
        }
    }
    cout << ans << "\n";

    return 0;
}