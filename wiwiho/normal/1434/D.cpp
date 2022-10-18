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

struct Node{
    int l = -1, r = -1;
    bool v = false;
    int even = 0, odd = 0;
    int reven(){
        return v ? odd : even;
    }
    int rodd(){
        return v ? even : odd;
    }
};

ostream& operator<<(ostream& o, Node n){
    return o << "(" << n.v << "," << n.even << "," << n.odd << ")";
}

vector<int> d1, d2, in1, in2, out1, out2, v1(1), v2(1);

struct SegmentTree{
    vector<Node> st;
    int ts = 0;
    int tmp = 1;
    SegmentTree(int sz){
        st.resize(2 * sz);
    }
    int build(int l, int r, vector<int>& d, vector<int>& v){
        int id = ts++;
        if(l == r){
            st[id].even = d[v[l]];
            return id;
        }
        int m = (l + r) / 2;
        st[id].l = build(l, m, d, v);
        st[id].r = build(m + 1, r, d, v);
        st[id].even = max(st[st[id].l].reven(), st[st[id].r].reven());
        st[id].odd = max(st[st[id].l].rodd(), st[st[id].r].rodd());
        return id;
    }
    void modify(int l, int r, int L, int R, int id){
        if(l == L && r == R){
            st[id].v = !st[id].v;
            return;
        }
        int M = (L + R) / 2;
        if(r <= M) modify(l, r, L, M, st[id].l);
        else if(l > M) modify(l, r, M + 1, R, st[id].r);
        else{
            modify(l, M, L, M, st[id].l);
            modify(M + 1, r, M + 1, R, st[id].r);
        }
        st[id].even = max(st[st[id].l].reven(), st[st[id].r].reven());
        st[id].odd = max(st[st[id].l].rodd(), st[st[id].r].rodd());
//        cerr << "pull" << tmp << " " << id << " " << st[id] << " " << st[st[id].l] << " " << st[st[id].r] << "\n";
    }
    void print(int l, int r, int id){
        cerr << "print" << tmp << " " << l << " " << r << ' ' << id << " " << st[id] << "\n";
        if(l == r){
            return;
        }
        int m = (l + r) / 2;
        print(l, m, st[id].l);
        print(m + 1, r, st[id].r);
    }
};

vector<vector<int>> g;
int ts = 0;

int f = -1;
void dfsf(int now, int p, vector<int>& d){
    d[now] = d[p] + 1;
    if(f == -1 || d[now] > d[f]) f = now;
    for(int i : g[now]){
        if(i == p) continue;
        dfsf(i, now, d);
    }
}

void dfs(int now, int p, vector<int>& in, vector<int>& out, vector<int>& v){
    in[now] = ts++;
    v.eb(now);
    for(int i : g[now]){
        if(i == p) continue;
        dfs(i, now, in, out, v);
    }
    out[now] = ts - 1;
}

int main(){
    StarBurstStream
    cerr.tie(0);

    int n;
    cin >> n;

    g.resize(n + 1);
    d1.resize(n + 1);
    d2.resize(n + 1);
    in1.resize(n + 1);
    in2.resize(n + 1);
    out1.resize(n + 1);
    out2.resize(n + 1);

    vector<pair<pii, bool>> e(n);
    for(int i = 1; i <= n - 1; i++){
        int u, v;
        bool t;
        cin >> u >> v >> t;
        e[i] = mp(mp(u, v), t);
        g[u].eb(v);
        g[v].eb(u);
    }

    f = -1;
    dfsf(1, 1, d1);
    int a = f;
    f = -1;
    d1[a] = 0;
    dfsf(a, a, d1);
    int b = f;
    dfsf(b, b, d2);
//    cerr << a << " " << b << "\n";

    ts = 1;
    dfs(a, a, in1, out1, v1);
    ts = 1;
    dfs(b, b, in2, out2, v2);
//    printv(v1, cerr);
//    printv(v2, cerr);

    SegmentTree s1(n), s2(n);
    s1.build(1, n, d1, v1);
    s2.build(1, n, d2, v2);
    s2.tmp = 2;

    for(int i = 1; i <= n - 1; i++){
        if(!e[i].S) continue;
        int u = e[i].F.F, v = e[i].F.S;
        if(d1[u] > d1[v]) s1.modify(in1[u], out1[u], 1, n, 0);
        else s1.modify(in1[v], out1[v], 1, n, 0);
        if(d2[u] > d2[v]) s2.modify(in2[u], out2[u], 1, n, 0);
        else s2.modify(in2[v], out2[v], 1, n, 0);
    }

//    s1.print(1, n, 0);
//    s2.print(1, n, 0);

    int m;
    cin >> m;
    while(m--){
        int id;
        cin >> id;
//        cerr << "test " << id << "\n";
        int u = e[id].F.F, v = e[id].F.S;
        if(d1[u] > d1[v]) s1.modify(in1[u], out1[u], 1, n, 0);
        else s1.modify(in1[v], out1[v], 1, n, 0);
        if(d2[u] > d2[v]) s2.modify(in2[u], out2[u], 1, n, 0);
        else s2.modify(in2[v], out2[v], 1, n, 0);
//        s1.print(1, n, 0);
//        s2.print(1, n, 0);
        cout << max(s1.st[0].reven(), s2.st[0].reven()) - 1 << "\n";
    }

    return 0;
}