//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define B back()
#define FR front()
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

ll dis(ll x1, ll y1, ll x2, ll y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

ll dis(pll a, pll b){
    return dis(a.F, a.S, b.F, b.S);
}

int main(){
    StarBurstStream

    ll x, y, ax, ay, bx, by;
    cin >> x >> y >> ax >> ay >> bx >> by;
    ll xs, ys, t;
    cin >> xs >> ys >> t;

    vector<pll> pt;
    for(int i = 0; i < 60; i++){
        if(dis(x, y, xs, ys) <= t) pt.eb(mp(x, y));
        x = ax * x + bx;
        y = ay * y + by;
        if(x > xs && y > ys && dis(x, y, xs, ys) > t) break;
    }

    int ans = 0;
    for(int i = 0; i < pt.size(); i++){
        for(int j = 0; j < pt.size(); j++){
            if(dis(xs, ys, pt[i].F, pt[i].S) + dis(pt[i], pt[j]) <= t) ans = max(ans, abs(j - i) + 1);
        }
    }
    cout << ans << "\n";

    return 0;
}