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
#define topos(a) (((a) % MOD + MOD) % MOD)
#define uni(a) a.resize(unique(iter(a)) - a.begin())
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
    if(b < 0) return 0;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int main(){
    StarBurstStream

    int m;
    cin >> m;

    vector<ll> a(m), f(m);
    for(int i = 0; i < m; i++) cin >> a[i] >> f[i];
    vector<vector<int>> t(100001);
    for(int i = 0; i < m; i++){
        ll tmp = a[i];
        for(ll j = 1; j * j <= tmp; j++){
            if(tmp % j) continue;
            t[j].eb(i);
            if(j != tmp / j) t[tmp / j].eb(i);
        }
    }

    vector<ll> ans(100001);

    for(int i = 100000; i > 0; i--){
        ll num = 0, sum = 0;
        for(int j : t[i]){
            num += f[j];
            sum += a[j] * f[j];
            sum %= MOD;
        }

        if(num <= 1) continue;

        for(int j : t[i]){
            ans[i] += a[j] * a[j] % MOD * f[j] % MOD * ((num - 1) % MOD) % MOD * fp(2, num - 2) % MOD;
            ans[i] %= MOD;
            ans[i] += a[j] * topos(sum - a[j]) % MOD * f[j] % MOD * (((num - 2) % MOD * fp(2, num - 3) % MOD + fp(2, num - 2)) % MOD) % MOD;
            ans[i] %= MOD;
//            cerr << i << " " << j << " " << a[j] << " " << f[j] << " " << a[j] * (sum - a[j]) * f[j] * ((num - 2) * fp(2, num - 3) + fp(2, num - 2)) << "\n";
        }

        for(ll j = 2; i * j <= 100000; j++){
            ans[i] -= ans[i * j];
            ans[i] = topos(ans[i]);
        }
    }

    cout << ans[1] << "\n";

    return 0;
}