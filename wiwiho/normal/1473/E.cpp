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

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<vector<pll>> g(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(mp(v, w));
        g[v].eb(mp(u, w));
    }

    vector<vector<ll>> dis(n + 1, vector<ll>(4, 1LL << 60));
    dis[1][0] = 0;
    std::priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<>> pq;
    pq.push(mp(0, mp(1, 0)));
    while(!pq.empty()){
        int now = pq.top().S.F;
        int t = pq.top().S.S;
        ll d = pq.top().F;
        pq.pop();
        if(dis[now][t] != d) continue;

        for(auto i : g[now]){
            if(d + i.S < dis[i.F][t]){
                dis[i.F][t] = d + i.S;
                pq.push(mp(dis[i.F][t], mp(i.F, t)));
            }
            if(!(t & 1) && d + 2 * i.S < dis[i.F][t | 1]){
                dis[i.F][t | 1] = d + 2 * i.S;
                pq.push(mp(dis[i.F][t | 1], mp(i.F, t | 1)));
            }
            if(!(t & 2) && d < dis[i.F][t | 2]){
                dis[i.F][t | 2] = d;
                pq.push(mp(dis[i.F][t | 2], mp(i.F, t | 2)));
            }
            if(t == 0 && d + i.S < dis[i.F][3]){
                dis[i.F][3] = d + i.S;
                pq.push(mp(dis[i.F][3], mp(i.F, 3)));
            }
        }
    }
    for(int i = 2; i <= n; i++){
        cout << dis[i][3] << " ";
    }
    cout << "\n";

    return 0;
}