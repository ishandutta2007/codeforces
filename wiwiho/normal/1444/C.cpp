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

vector<vector<int>> g;
vector<int> c;
vector<int> id, t;
bool f = true;

void dfs(int now, int ts, int clr){
    t[now] = clr;
    id[now] = ts;
    for(int i : g[now]){
        if(id[i] != -1){
            if(clr == t[i]) f = false;
            continue;
        }
        dfs(i, ts, !clr);
    }
}

bool tf = true;
void check(int now, int clr, map<int, vector<int>>& tg, map<int, int>& c){
    c[now] = clr;
    for(int i : tg[now]){
        if(c.find(i) != c.end()){
            if(c[i] == clr){
                tf = false;
            }
            continue;
        }
        check(i, !clr, tg, c);
    }
}

int main(){
    StarBurstStream

    int n, m, k;
    cin >> n >> m >> k;

    g.resize(n + 1);
    c.resize(n + 1);
    t.resize(n + 1, -1);
    id.resize(n + 1, -1);

    for(int i = 1; i <= n; i++) cin >> c[i];

    map<pii, vector<pii>> e;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(c[u] == c[v]){
            g[u].eb(v);
            g[v].eb(u);
            continue;
        }
        if(c[u] > c[v]) swap(u, v);
//        cerr << u << " " << v << " " << c[u] << " " << c[v] << "\n";
        e[mp(c[u], c[v])].eb(mp(u, v));
    }

    int ts = 0;
    vector<bool> ok(k + 1, true);
    ll cnt = 0;
    for(int i = 1; i <= n; i++){
        if(id[i] != -1) continue;
        f = true;
        dfs(i, ts++, 0);
        if(!f) ok[c[i]] = false;
    }
    for(int i = 1; i <= k; i++){
        if(ok[i]) cnt++;
    }
//    printv(id, cerr);
//    printv(ok, cerr);

    ll ans = cnt * (cnt - 1) / 2;

    for(auto& i : e){
        int gu, gv;
        tie(gu, gv) = i.F;
        if(!ok[gu] || !ok[gv]) continue;
//        cerr << "test " << gu << ' ' << gv << "\n";
        map<int, vector<int>> tg;
        set<int> st;
        for(auto j : i.S){
            int u, v;
            tie(u, v) = j;
            st.insert(id[u]);
            st.insert(id[v]);
            u = t[u] * n + id[u];
            v = t[v] * n + id[v];
            tg[u].eb(v);
            tg[v].eb(u);
        }
        for(int j : st){
            tg[j].eb(j + n);
            tg[j + n].eb(j);
        }
//        for(auto& j : tg){
//            cerr << j.F << "  ";
//            printv(j.S, cerr);
//        }
        map<int, int> c;
        tf = true;
        for(int j : st){
            if(c.find(j) != c.end()) continue;
            check(j, 1, tg, c);
        }
//        printv(c, cerr);
        if(!tf){
//            cerr << gu << " " << gv << "\n";
            ans--;
        }
    }

    cout << ans << "\n";

    return 0;
}