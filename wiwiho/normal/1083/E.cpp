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

struct Line{
    ll l, r, a, b;
    Line(ll a = 0, ll b = 0, ll l = -MAX, ll r = MAX) : a(a), b(b), l(l), r(r) {}
    ll operator()(ll x){
        return a * x + b;
    }
};

ostream& operator<<(ostream& o, Line ln){
    return o << '(' << ln.l << ',' << ln.r << ',' << ln.a << ',' << ln.b << ')';
}

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<pair<pll, ll>> p(n);
    for(int i = 0; i < n; i++){
        ll x, y, a;
        cin >> x >> y >> a;
        p[i] = mp(mp(x, y), a);
    }
    lsort(p);

    deque<Line> dq;
    dq.eb(Line());

    vector<ll> dp(n);
    for(int i = 0; i < n; i++){
        ll x = p[i].F.F, y = p[i].F.S, a = p[i].S;

        while(dq.back().l > y) dq.pob;
        dp[i] = dq.back()(y) + x * y - a;

        Line ln(-x, dp[i]);
        while(!dq.empty() && dq.front()(dq.front().r) <= ln(dq.front().r)){
            dq.pof;
        }

        if(dq.empty()){
            dq.eb(ln);
        }
        else{
            if(dq.front()(dq.front().l) >= ln(dq.front().l)){
                if(dq.front().l > -MAX){
                    ln.r = dq.front().l - 1;
                    dq.ef(ln);
                }
                continue;
            }
            ll pos = ifloor(ln.b - dq.front().b, dq.front().a - ln.a);
            dq.front().l = pos + 1;
            ln.r = pos;
            dq.ef(ln);
        }

//        printv(dq, cerr);
    }

    cout << *max_element(iter(dp)) << "\n";

    return 0;
}