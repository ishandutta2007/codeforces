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

vector<ll> f, finv;

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

ll c(ll n, ll k){
    if(n < k) return 0;
    return f[n] * finv[k] % MOD * finv[n - k] % MOD;
}

ll h(ll n, ll k){
    return c(n + k - 1, k);
}

vector<int> lpd, prime;

void sieve(int n){
    lpd.resize(n, 1);
    for(int i = 2; i <= n; i++){
        if(lpd[i] == 1){
            lpd[i] = i;
            prime.eb(i);
        }
        for(ll j : prime){
            if(i * j > n) break;
            lpd[i * j] = j;
            if(j == lpd[i]) break;
        }
    }
}

int main(){
    StarBurstStream

    f.resize(2500001);
    finv.resize(2500001);
    f[0] = finv[0] = 1;
    for(int i = 1; i <= 2500000; i++){
        f[i] = f[i - 1] * i % MOD;
        finv[i] = inv(f[i]);
    }
    sieve(1000000);

    vector<ll> two(1000001);
    two[0] = 1;
    for(int i = 1; i <= 1000000; i++){
        two[i] = two[i - 1] * 2 % MOD;
    }

    int T;
    cin >> T;
    while(T--){

        ll x, y;
        cin >> x >> y;

        ll ans = 1;
        while(x > 1){

            ll now = lpd[x];
            ll cnt = 0;
            while(x % now == 0){
                cnt++;
                x /= now;
            }

            ans = ans * h(y, cnt) % MOD;
        }
        if(x > 1) ans = ans * y % MOD;

//        cerr << ans << "\n";

        ans = ans * two[y - 1] % MOD;

        cout << ans << "\n";

    }

    return 0;
}