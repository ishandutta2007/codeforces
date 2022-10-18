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
#define iceil(a, b) ((a + b - 1) / b)
#define tomax(a, b) (a = max(a, b))
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

vector<int> pr;
vector<vector<int>> g;

struct DSU{

    vector<int> dsu;
    int ts;

    DSU(int n){
        dsu.resize(2 * n + 1);
        for(int i = 1; i <= 2 * n; i++) dsu[i] = i;
        ts = n + 1;
    }

    int findDSU(int a){
        if(dsu[a] != a) dsu[a] = findDSU(dsu[a]);
        return dsu[a];
    }

    void unionDSU(int a, int b){
        a = findDSU(a), b = findDSU(b);
        if(a == b) return;
        int c = ts++;
        dsu[a] = c;
        dsu[b] = c;
        pr[a] = pr[b] = c;
        g[c].eb(a); g[c].eb(b);
    }

};

vector<int> a;

int argmax(int x, int y){
    return a[x] >= a[y] ? x : y;
}

struct Node{
    int l = -1, r = -1;
    int v = 0;
};

struct SegmentTree{

    vector<Node> st;
    int ts;

    SegmentTree(int n){
        st.resize(4 * n);
        ts = 0;
    }

    int build(int l, int r){
        int id = ts++;
        if(l == r){
            st[id].v = l;
            return id;
        }
        int m = (l + r) / 2;
        st[id].l = build(l, m);
        st[id].r = build(m + 1, r);
        st[id].v = argmax(st[st[id].l].v, st[st[id].r].v);
//        cerr << "build " << l << " " << r << " " << st[id].v << "\n";
        return id;
    }

    void modify(int x, int L, int R, int id){
        if(L == R) return;
        int M = (L + R) / 2;
        if(x <= M) modify(x, L, M, st[id].l);
        else modify(x, M + 1, R, st[id].r);
        st[id].v = argmax(st[st[id].l].v, st[st[id].r].v);
    }

    int query(int l, int r, int L, int R, int id){
        if(l == L && r == R) return st[id].v;
        int M = (L + R) / 2;
        if(r <= M) return query(l, r, L, M, st[id].l);
        else if(l > M) return query(l, r, M + 1, R, st[id].r);
        else{
            return argmax(query(l, M, L, M, st[id].l), query(M + 1, r, M + 1, R, st[id].r));
        }
    }

};

vector<int> in, out;
int ts = 0;

void dfs(int now){
    in[now] = ++ts;
    for(int i : g[now]) dfs(i);
    out[now] = ts;
}

int main(){
    StarBurstStream
    cerr.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    pr.resize(2 * n + 1);
    g.resize(2 * n + 1);

    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];

    vector<pii> qry(q);
    vector<pii> e(m + 1);
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        e[i] = mp(u, v);
    }

    DSU dsu(n);

    vector<bool> ers(m + 1);
    for(int i = 0; i < q; i++){
        cin >> qry[i].F >> qry[i].S;
        if(qry[i].F == 2) ers[qry[i].S] = true;
    }
    for(int i = 1; i <= m; i++){
        if(ers[i]) continue;
        qry.eb(mp(2, i));
    }

    vector<int> pos(qry.size());

    reverse(iter(qry));

    for(int i = 0; i < qry.size(); i++){
        if(qry[i].F == 1) pos[i] = dsu.findDSU(qry[i].S);
        else dsu.unionDSU(e[qry[i].S].F, e[qry[i].S].S);
    }

    in.resize(2 * n + 1, -1);
    out.resize(2 * n + 1, -1);
    for(int i = 1; i <= 2 * n; i++){
        int t = dsu.findDSU(i);
        if(in[t] == -1) dfs(t);
    }

    a.resize(2 * n + 1);
    for(int i = 1; i <= n; i++){
        a[in[i]] = p[i];
    }

    SegmentTree st(n);
    st.build(1, 2 * n);

    reverse(iter(qry));
    reverse(iter(pos));
//    printv(pos, cerr);
//    printv(in, cerr);
//    printv(out, cerr);
//    printv(a, cerr);

    for(int i = 0; i < q; i++){
        if(qry[i].F == 2) continue;
        int pp = pos[i];
        int t = st.query(in[pp], out[pp], 1, 2 * n, 0);
//        cerr << t << "  ";
//        printv(a, cerr);
        cout << a[t] << "\n";
        a[t] = 0;
        st.modify(t, 1, 2 * n, 0);
    }

    return 0;
}