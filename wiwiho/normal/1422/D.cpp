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
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
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

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;

    vector<vector<pll>> g(m);
    vector<pii> x(m), y(m);
    vector<pii> p(m);
    vector<ll> dis(m, MAX);
    for(int i = 0; i < m; i++){
        cin >> x[i].F >> y[i].F;
        x[i].S = y[i].S = i;
        p[i] = mp(x[i].F, y[i].F);
        dis[i] = min(abs(x[i].F - sx), abs(y[i].F - sy));
    }

    lsort(x); lsort(y);

    for(int i = 0; i < m - 1; i++){
        g[x[i].S].eb(mp(x[i + 1].S, x[i + 1].F - x[i].F));
        g[x[i + 1].S].eb(mp(x[i].S, x[i + 1].F - x[i].F));
        g[y[i].S].eb(mp(y[i + 1].S, y[i + 1].F - y[i].F));
        g[y[i + 1].S].eb(mp(y[i].S, y[i + 1].F - y[i].F));
    }

    std::priority_queue<pll, vector<pll>, greater<>> pq;
    for(int i = 0; i < m; i++) pq.push(mp(dis[i], i));

    while(!pq.empty()){
        int now = pq.top().S;
        ll d = pq.top().F;
        pq.pop();
        if(d != dis[now]) continue;
        for(pll i : g[now]){
            if(dis[i.F] <= d + i.S) continue;
            dis[i.F] = d + i.S;
            pq.push(mp(dis[i.F], i.F));
        }
    }
//    printv(dis, cerr);

    ll ans = abs(fx - sx) + abs(fy - sy);
    for(int i = 0; i < m; i++){
//        cerr << i << " " << dis[i] << " " << p[i] << " " << abs(p[i].F - fx) + abs(p[i].S - fy) << "\n";
        ans = min(ans, dis[i] + (ll)abs(p[i].F - fx) + abs(p[i].S - fy));
    }
    cout << ans << "\n";

    return 0;
}