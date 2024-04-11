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

vector<pair<char, pll>> ans;

void make(ll x, ll n){
    ll now = 0;
    while(n > 0){
        if(n & 1){
            ans.eb(mp('+', mp(now, x)));
            now += x;
        }
        ans.eb(mp('+', mp(x, x)));
        x += x;
        n >>= 1;
    }
}

pll exgcd(ll a, ll b){
    if(b == 0) return mp(1, 0);
    pll t = exgcd(b, a - a / b * b);
    return mp(t.S, t.F - a / b * t.S);
}

int main(){
    StarBurstStream

    ll x;
    cin >> x;

    ans.eb(mp('^', mp(x, x)));

    int e = 64 - __builtin_clzll(x) - 1;

    make(x, 1LL << e);
    ans.eb(mp('^', mp(x, x * (1LL << e))));

    ll yy = x ^ (x * (1LL << e)), xx = x;
    pll t = exgcd(xx, -yy);
//    cerr << t << "\n";
    if(t.F * xx - t.S * yy == -1) t.F *= -1, t.S *= -1;
//    cerr << t << "\n";
    ll t1 = t.F < 1 ? iceil(-t.F, yy) : 0;
    ll t2 = t.S < 1 ? iceil(-t.S, xx) : 0;
    t1 = max(t1, t2);
//    cerr << x << " " << yy << " " << t << " " << t1 << "\n";
    t.F += yy * t1; t.S += xx * t1;
    if(t.S % 2) t.S += xx, t.F += yy;
//    cerr << t << "\n";
//    cerr << xx * t.F << " " << yy * t.S << "\n";

    make(xx, t.F);
    make(yy, t.S);

    ans.eb(mp('^', mp(xx * t.F, yy * t.S)));

    cout << ans.size() << "\n";
    for(auto i : ans){
        cout << i.S.F << " " << i.F << " " << i.S.S << "\n";
    }

    return 0;
}