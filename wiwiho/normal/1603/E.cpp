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

ll MOD = 1000000007;
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

int n;

vector<ll> f, invf;
vector<vector<vector<ll>>> dp;
vector<vector<vector<int>>> lst;

ll calc(int i, int sum, int k, int a1){
    if(i == n && k == 0) return 0;
    if(i == n) return f[n];
    if(k == 0){
        //cerr << "calc " << i << " " << sum << " " << k << " " << a1 << ": " << f[n] * invf[n - i] % MOD << "\n";
        return f[n] * invf[n - i] % MOD;
    }
    if(lst[i][sum][k] == a1) return dp[i][sum][k];
    lst[i][sum][k] = a1;
    dp[i][sum][k] = 0;
    for(int c = (a1 - sum) / k; c >= 0; c--){
        if(k > 1 && i + c < n + 2 - a1 - k) continue;
        //cerr << i << " " << sum << " " << k << " " << c << "\n"
            //<< i + c << " " << sum + c * k << " " << k - 1 << "\n";
        dp[i][sum][k] += calc(i + c, sum + c * k, k - 1, a1) * invf[c];
        dp[i][sum][k] %= MOD;
    }
    return dp[i][sum][k];
}

int main(){
    StarBurstStream

    cin >> n >> MOD;
    f.resize(n + 5);
    invf.resize(n + 5);
    f[0] = invf[0] = 1;
    for(int i = 1; i <= n + 4; i++){
        f[i] = f[i - 1] * i % MOD;
        invf[i] = inv(f[i]);
    }
    //printv(f, cerr);
    //printv(invf, cerr);

    dp.resize(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1)));
    lst.resize(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));

    ll ans = 0;
    for(int a1 = max(1, n - 40); a1 <= n + 1; a1++){
        ll tmp = calc(0, 0, n + 1 - a1, a1);
        //cerr << "test " << a1 << " " << tmp << "\n";
        ans += tmp;
        ans %= MOD;
    }
    cout << ans << "\n";

    return 0;
}