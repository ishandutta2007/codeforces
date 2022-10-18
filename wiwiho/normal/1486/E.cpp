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
const ll MAX = 1LL << 60;

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

    vector<vector<ll>> dis(n + 1, vector<ll>(51, MAX));
    dis[1][0] = 0;
    std::priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<>> pq;
    pq.push(mp(0, mp(1, 0)));
    while(!pq.empty()){
        int now = pq.top().S.F, w = pq.top().S.S;
        ll d = pq.top().F;
        pq.pop();
        if(d != dis[now][w]) continue;
        for(pll i : g[now]){
            if(w == 0){
                ll nd = d + i.S * i.S;
                if(dis[i.F][i.S] <= nd) continue;
                dis[i.F][i.S] = nd;
                pq.push(mp(nd, i));
            }
            else{
                ll nd = d + i.S * i.S + 2 * w * i.S;
                if(dis[i.F][0] <= nd) continue;
                dis[i.F][0] = nd;
                pq.push(mp(nd, mp(i.F, 0)));
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(dis[i][0] == MAX) cout << "-1 ";
        else cout << dis[i][0] << " ";
    }
    cout << "\n";

    return 0;
}