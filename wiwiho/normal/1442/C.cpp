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

const ll MOD = 998244353;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

bool comp(pll a, pll b){
    if(max(a.F, b.F) > 50) return a > b;
    return ((1LL << (a.F + 1)) - 1) + a.S > ((1LL << (b.F + 1)) - 1) + b.S;
}

struct Comp{
    bool operator()(pair<pll, int> a, pair<pll, int> b){
        return comp(a.F, b.F);
    }
};

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> g(n + 1), r(n + 1);

    for(int i = 0; i < m ;i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        r[v].eb(u);
    }

    vector<map<ll, ll>> odddis(n + 1), evendis(n + 1);
    std::priority_queue<pair<pll, int>, vector<pair<pll, int>>, Comp> pq;
    odddis[1][-1] = 0;
    pq.push(mp(mp(-1, 0), 1));
    while(!pq.empty()){
        int v = pq.top().S;
        ll t = pq.top().F.F;
        ll d = pq.top().F.S;
        pq.pop();
        auto& dis = t % 2 ? odddis : evendis;
        if(dis[v].find(t) == dis[v].end() || dis[v][t] != d) continue;
        for(int i : g[v]){
            ll nt = t + !(t % 2);
            ll nd = d + 1;
            auto& dis = nt % 2 ? odddis : evendis;
            auto it = dis[i].upper_bound(nt);
            if(it != dis[i].begin()){
                it--;
                if(comp(mp(nt, nd), *it) || mp(it->F, it->S) == mp(nt, nd)) continue;
            }
//            cerr << "test1 " << v << " " << t << ' ' << d << " " << i << " " << nt << " " << nd << "\n";
            dis[i][nt] = nd;
            pq.push(mp(mp(nt, nd), i));
            it = dis[i].upper_bound(nt);
            while(it != dis[i].end() && comp(*it, mp(nt, nd))){
//                cerr << "del " << *it << " " << mp(nt, nd) << " " << (1LL << nt) + nd << "\n";
                it = dis[i].erase(it);
            }
        }
        for(int i : r[v]){
            ll nt = t + !!(t % 2);
            ll nd = d + 1;
            auto& dis = nt % 2 ? odddis : evendis;
            auto it = dis[i].upper_bound(nt);
            if(it != dis[i].begin()){
                it--;
                if(comp(mp(nt, nd), *it) || mp(it->F, it->S) == mp(nt, nd)) continue;
            }
//            cerr << "test2 " << v << " " << t << ' ' << d << " " << i << " " << nt << " " << nd << "\n";
            dis[i][nt] = nd;
            pq.push(mp(mp(nt, nd), i));
            it = dis[i].upper_bound(nt);
            while(it != dis[i].end() && comp(*it, mp(nt, nd))){
//                cerr << "del " << *it << " " << mp(nt, nd) << " " << (1LL << nt) + nd << "\n";
                it = dis[i].erase(it);
            }
        }
    }

//    for(int i = 1; i <= n; i++){
//        cerr << i << "  ";
//        printv(dis[i], cerr);
//    }

    pll ans = mp(MAX, 0);
    for(auto i : odddis[n]){
        if(comp(ans, i)) ans = i;
    }
    for(auto i : evendis[n]){
        if(comp(ans, i)) ans = i;
    }

    assert(ans.F != MAX);

    ll aaa = 1;
    for(int i = 0; i <= ans.F; i++){
        aaa = aaa * 2 % MOD;
    }
    aaa--;
    aaa = topos(aaa);
    aaa += ans.S;
    aaa %= MOD;

    cout << aaa << "\n";

    return 0;
}