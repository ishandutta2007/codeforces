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

int main(){
    StarBurstStream

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pii>> g(n + 1);
    vector<pii> es(m);

    for(int i = 0; i < m ;i++){
        int u, v, w;
        cin >> u >> v >> w;
        es[i] = mp(u, v);
        g[u].eb(mp(v, w));
        g[v].eb(mp(u, w));
    }

    vector<vector<ll>> dis(n + 1, vector<ll>(n + 1, MAX));
    for(int i = 1; i <= n; i++){
        dis[i][i] = 0;
        std::priority_queue<pll, vector<pll>, greater<>> pq;
        pq.push(mp(0, i));
        while(!pq.empty()){
            int v = pq.top().S;
            ll d = pq.top().F;
            pq.pop();
            if(d != dis[i][v]) continue;
            for(pll e : g[v]){
                if(d + e.S < dis[i][e.F]){
                    dis[i][e.F] = d + e.S;
                    pq.push(mp(d + e.S, e.F));
                }
            }
        }
    }

//    for(int i = 1; i <= n; i++) printv(dis[i], cerr);

    vector<ll> ans(m);
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        for(int j = 0; j < m; j++){
            int u = es[j].F, v = es[j].S;
            ans[j] += min({dis[a][b], dis[a][u] + dis[v][b], dis[a][v] + dis[u][b]});
        }
    }

    cout << *min_element(iter(ans)) << "\n";


    return 0;
}