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

ll x, y;
ll c1, c2, c3, c4, c5, c6;

ll calc(ll t){
    ll nx = 0, ny = 0;
    ll ans = 0;
    if(t < 0) ans += c4 * (-t);
    else ans += c1 * t;
    nx = t, ny = t;
    if(x - nx < 0) ans += c3 * (nx - x);
    else ans += c6 * (x - nx);
    if(y - ny < 0) ans += c5 * (ny - y);
    else ans += c2 * (y - ny);
    return ans;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){
        cin >> x >> y;
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;

        ll l = -1000000005, r = 1000000005;
        while(l < r){
//            cerr << l << " " << r << "\n";
            ll m = l + r < 0 ? (l + r - 1) / 2 : (l + r) / 2;
            if(calc(m) <= calc(m + 1)) r = m;
            else l = m + 1;
        }

        cout << calc(l) << "\n";
    }

    return 0;
}