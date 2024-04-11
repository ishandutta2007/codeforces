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

ll calc(vector<pll>& p, ll len){
    vector<ll> x = {p[0].F, p[2].F, p[1].F - len, p[3].F - len};
    vector<ll> y = {p[2].S, p[3].S, p[0].S - len, p[1].S - len};
    lsort(x);
    lsort(y);
    ll l = x[1], d = y[1], r = l + len, u = d + len;
    return abs(p[0].F - l) + abs(p[0].S - u) + abs(p[1].F - r) + abs(p[1].S - u) +
           abs(p[2].F - l) + abs(p[2].S - d) + abs(p[3].F - r) + abs(p[3].S - d);
}

ll check(vector<pll>& p){
    ll x1 = p[0].F, x2 = p[2].F, x3 = p[1].F, x4 = p[3].F;
    if(x1 > x2) swap(x1, x2);
    if(x3 > x4) swap(x3, x4);
    vector<ll> t;
    t.eb(x3 - x2);
    t.eb(x4 - x1);

    ll y1 = p[2].S, y2 = p[3].S, y3 = p[0].S, y4 = p[1].S;
    if(y1 > y2) swap(y1, y2);
    if(y3 > y4) swap(y3, y4);
    t.eb(y3 - y2);
    t.eb(y4 - y1);

//    printv(p, cerr);
//    printv(t, cerr);
    lsort(t);
    ll len = max(0LL, t[1]);
//    ll len = t[1];
//    cerr << len << " " << calc(p, len) << " " << calc(p, 0) << " " << calc(p, 1) << "\n";
//    for(int i = -10; i < 10 || len + i <= 10; i++) cerr << calc(p, len + i) << " ";
//    cerr << "\n";
    return calc(p, len);
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        vector<pll> p(4);
        for(int i = 0; i < 4; i++) cin >> p[i].F >> p[i].S;
        lsort(p);

        ll ans = 1LL << 60;
        do{
            ans = min(ans, check(p));
        }
        while(next_permutation(iter(p)));
        cout << ans << "\n";

    }

    return 0;
}