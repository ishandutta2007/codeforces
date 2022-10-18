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

vector<ll> f, invf, two;

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
    if(n < k || k < 0) return 0;
    return f[n] * invf[k] % MOD * invf[n - k] % MOD;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;
    f.resize(n + 1);
    invf.resize(n + 1);
    two.resize(n + 1);
    f[0] = invf[0] = 1;
    two[0] = 1;
    for(int i = 1; i <= n; i++) f[i] = f[i - 1] * i % MOD, invf[i] = inv(f[i]);
    for(int i = 1; i <= n; i++) two[i] = two[i - 1] * 2 % MOD;

    int cl = 0, cr = 0, same = 0;
    int lw = 0, rw = 0, lb = 0, rb = 0;
    int cnt = 0, c2 = 0;
    int wb = 0, bw = 0;
    
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;

        if(s[0] == '?') cl++;
        else if(s[0] == 'W') lw++;
        else lb++;
        if(s[1] == '?') cr++;
        else if(s[1] == 'W') rw++;
        else rb++;

        if(s == "WW" || s == "BB") same++;
        if(s == "BW") bw++;
        if(s == "WB") wb++;

        if(s[0] == '?' || s[1] == '?') cnt++;
        if(s == "??") c2++;
    }

    ll ans = 0;
    for(int i = 0; i <= n; i++){
        ans += C(cl, i - lw) * C(cr, i - rb) % MOD;
        ans %= MOD;
        //cerr << i << " " << lw - i << " " << rb - i << "\n";
    }
    //cerr << ans << "\n";

    if(!same){
        ans -= two[c2];

        if(bw == 0 && lb == 0 && rw == 0) ans++;
        if(wb == 0 && lw == 0 && rb == 0) ans++;
    }

    topos(ans);
    
    cout << ans << "\n";

    return 0;
}