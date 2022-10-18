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
const ll MAX = 1LL << 60;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<vector<pll>> g(n + 1, vector<pll>(n + 1, mp(MAX, MAX)));
    vector<pair<pii, int>> e(m);

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v].F = g[v][u].F = w;
        e[i] = mp(mp(u, v), w);
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int u, v, l;
        cin >> u >> v >> l;
        g[u][v].S = g[v][u].S = -l;
    }

    for(int t = 0; t < 2; t++) for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                g[i][j].F = min(g[i][j].F, g[i][k].F + g[k][j].F);
                g[i][j].S = min({g[i][j].S, g[i][k].F + g[k][j].S, g[i][k].S + g[k][j].F});
            }
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                ll o = g[i][j].S;
                g[i][j].F = min(g[i][j].F, g[i][k].F + g[k][j].F);
                g[i][j].S = min({g[i][j].S, g[i][k].F + g[k][j].S, g[i][k].S + g[k][j].F});
                assert(o == g[i][j].S);
            }
        }
    }

    int ans = 0;
    for(auto& i : e){
        int u = i.F.F, v = i.F.S, w = i.S;
        if(g[u][v].S + w <= 0) ans++;
    }

    cout << ans << "\n";

    return 0;
}