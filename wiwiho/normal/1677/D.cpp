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

const ll MOD = 998244353;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
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

vector<ll> f, invf;
ll C(int n, int k){
    return f[n] * invf[k] % MOD * invf[n - k] % MOD;
}


void solve(){
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    if(v[1] > 0){
        cout << "0\n";
        return;
    }
    v[1] = 0;

    for(int i = 1; i <= k && n - i + 1 >= 1; i++){
        if(v[n - i + 1] > 0){
            cout << "0\n";
            return;
        }
        v[n - i + 1] = 0;
    }

    //printv(v, cerr);
    

    ll ans = 1;
    for(int i = 1; i <= k; i++) ans = ans * i % MOD;
    for(int i = 1; i <= n - k; i++){
        //cerr << i << "\n";
        if(v[i] == 0){
            ans = ans * (k + 1) % MOD;
        }
        else if(v[i] > 0);
        else{
            ans = ans * (k + i) % MOD;
        }
    }
    cout << ans << "\n";

    return;

    /*int cnt = 0, oao = 0;
    for(int i = 1; i <= n; i++){
        if(v[i] == 0) cnt++;
        if(v[i] == -1) oao++;
    }

    vector<ll> dp(n + 1);
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        if(i <= k) dp[i] = dp[i - 1] * i % MOD;
        else dp[i] = dp[i - 1] * (k + 1) % MOD;
    }

    ll ans = 0;
    for(int i = cnt; i <= cnt + oao; i++){
        ans += dp[i] * C(oao, i - cnt) % MOD;
        ans %= MOD;
    }

    cout << ans << "\n";*/
}

int main(){
    StarBurstStream

    f.resize(1000001);
    invf.resize(1000001);
    f[0] = invf[0] = 1;
    for(int i = 1; i <= 1000000; i++){
        f[i] = f[i - 1] * i % MOD;
        invf[i] = inv(f[i]);
    }

    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}