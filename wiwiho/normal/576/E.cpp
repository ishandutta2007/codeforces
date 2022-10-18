#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define eb(a) emplace_back(a)
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; \
    pvaspace=true;\
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

int n, m, q, K;

struct DSU{
    vector<int> dsu, sz, tag;
    vector<pii> opt;
    void init(){
        dsu.resize(n + 1);
        sz.resize(n + 1, 1);
        tag.resize(n + 1);
        iota(iter(dsu), 0);
    }
    pii findDSU(int a){ // root, color
        //cerr << "findDSU " << a << "\n";
        int tmp = tag[a];
        while(a != dsu[a]){
            a = dsu[a];
            tmp ^= tag[a];
        }
        return mp(a, tmp);
    }
    void unionDSU(int a, int b){
        pii pa = findDSU(a);
        pii pb = findDSU(b);
        a = pa.F;
        b = pb.F;
        int ca = pa.S;
        int cb = pb.S;

        if(a == b){
            opt.eb(mp(-1, 0));
            return;
        }
        if(sz[a] < sz[b]){
            swap(a, b);
            swap(ca, cb);
        }

        sz[a] += sz[b];
        dsu[b] = a;
        if(ca == cb){
            tag[b] = !tag[b];
            opt.eb(mp(b, 1));
        }
        else opt.eb(mp(b, 0));
    }
    void undo(){
        int v = opt.back().F, ch = opt.back().S;
        opt.pob;
        if(v == -1) return;
        sz[dsu[v]] -= sz[v];
        dsu[v] = v;
        if(ch) tag[v] = !tag[v];
    }
    bool check(int a, int b){
        pii ta = findDSU(a);
        pii tb = findDSU(b);
        return ta.F != tb.F || ta.S != tb.S;
    }
};

struct event{
    int id, c;
};

vector<vector<event>> st;
vector<pii> edge;
vector<pii> qry;
vector<bool> ans;
vector<DSU> dsu;
vector<vector<int>> ch;
vector<int> clr;
#define lc 2 * id + 1
#define rc 2 * id + 2

void modify(int l, int r, event e, int L = 0, int R = q, int id = 0){
    //cerr << "modify " << l << " " << r << " " << L << " " << R << "\n";
    if(l <= L && R <= r){
        st[id].eb(e);
        return;
    }
    int M = (L + R) / 2;
    if(r <= M) modify(l, r, e, L, M, lc);
    else if(l > M) modify(l, r, e, M + 1, R, rc);
    else{
        modify(l, r, e, L, M, lc);
        modify(l, r, e, M + 1, R, rc);
    }
}

void dfs(int L = 0, int R = q, int id = 0){

    vector<pii> oc;
    for(event i : st[id]){
        int e = i.id, c = i.c;
        dsu[c].unionDSU(edge[e].F, edge[e].S);
        oc.eb(mp(e, clr[e]));
        clr[e] = c;
    }

    if(L == R){
        if(L == q) return;
        int e, c;
        tie(e, c) = qry[L + 1];
        int u, v;
        tie(u, v) = edge[e];
        
        //cerr << "dfs " << L << " " << c << " " << u << " " << v << "\n";
        //printv(ch[e], cerr);
        if(dsu[c].check(u, v)){
            ans[L + 1] = true;
            modify(L + 1, *upper_bound(iter(ch[e]), L + 1) - 1, event({e, c}));
        }
        else{
            ans[L + 1] = false;
            if(clr[e] != -1) modify(L + 1, *upper_bound(iter(ch[e]), L + 1) - 1, event({e, clr[e]}));
        }
    }
    else{
        int M = (L + R) / 2;
        dfs(L, M, lc);
        dfs(M + 1, R, rc);
    }

    for(pii i : oc){
        dsu[clr[i.F]].undo();
        clr[i.F] = i.S;
    }
}

int main(){
    StarBurstStream
    cin >> n >> m >> K >> q;
    st.resize(4 * (q + 1));
    edge.resize(m + 1);
    dsu.resize(K + 1);
    qry.resize(q + 1);
    ans.resize(q + 1);
    ch.resize(m + 1);
    clr.resize(m + 1, -1);
    for(int i = 1; i <= K; i++) dsu[i].init();

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        edge[i] = {u, v};
    }

    /*if(K == 1){
        for(int i = 1; i <= q; i++){
            int e, c;
            cin >> e >> c;
            int u, v;
            tie(u, v) = edge[e];
            if(!dsu[c].check(u, v)){
                cout << "NO\n";
                continue;
            }
            dsu[c].unionDSU(u, v);
            cout << "YES\n";
        }
        return 0;
    }*/

    for(int i = 1; i <= q; i++){
        int e, c;
        cin >> e >> c;
        qry[i] = {e, c};
        ch[e].eb(i);
    }
    for(int i = 1; i <= m; i++){
        ch[i].eb(q + 1);
    }
    //printv(qry, cerr);

    dfs();

    for(int i = 1; i <= q; i++){
        if(ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}