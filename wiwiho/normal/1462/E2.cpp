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

ll c(ll n, ll k){
    if(n < k) return 0;
    return f[n] * inv(f[k]) % MOD * inv(f[n - k]) % MOD;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    f.resize(200001);
    f[0] = 1;
    for(int i = 1; i <= 200000; i++) f[i] = f[i - 1] * i % MOD;

    while(T--){

        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        lsort(a);

        int rp = 0;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            while(rp < n - 1 && a[rp + 1] <= a[i] + k) rp++;
            ll cnt = rp - i;
            ans += c(cnt, m - 1);
            ans %= MOD;
        }

        cout << ans << "\n";

    }


    return 0;
}