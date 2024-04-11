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

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll inv(ll a){
    ll b = MOD - 2;
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

vector<ll> f;

ll p(ll n, ll k){
    if(k > n) return 0;
    return f[n] * inv(f[n - k]) % MOD;
}

int main(){
    StarBurstStream

    int n, x, pos;
    cin >> n >> x >> pos;

    f.resize(n + 1);
    f[0] = 1;
    for(int i = 1; i <= n; i++) f[i] = f[i - 1] * i % MOD;

    int s = 0, g = 0;
    int l = 0, r = n;
    while(l < r){
        int m = (l + r) / 2;
        if(m == pos) l = m + 1;
        else if(m < pos){
            l = m + 1;
            s++;
//            cerr << "s" << " " << m << "\n";
        }
        else{
            r = m;
            g++;
//            cerr << "g" << " " << m << "\n";
        }
    }
//    cerr << s << " " << g << "\n";
//    cerr << p(x - 1, s) << " " << p(n - x, g) << " " << f[n - s - g - 1] << "\n";

    ll ans = p(x - 1, s) * p(n - x, g) % MOD * f[n - s - g - 1] % MOD;
    cout << ans << "\n";

    return 0;
}