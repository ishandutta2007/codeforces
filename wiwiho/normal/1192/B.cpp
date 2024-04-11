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

int n, q;
ll W;

struct Node{
    ll mx = 0, mn = 0;
    ll lm = 0, mr = 0, lmr = 0;
    ll tag = 0;
};

vector<Node> st;
#define lc 2 * id + 1
#define rc 2 * id + 2

void pull(int id){
    st[id].mx = max(st[lc].mx, st[rc].mx);
    st[id].mn = min(st[lc].mn, st[rc].mn);
    st[id].lm = max({st[lc].mx - 2 * st[rc].mn, st[lc].lm, st[rc].lm});
    st[id].mr = max({-2 * st[lc].mn + st[rc].mx, st[lc].mr, st[rc].mr});
    st[id].lmr = max({st[lc].lm + st[rc].mx, st[lc].mx + st[rc].mr, st[lc].lmr, st[rc].lmr});
}

void addtag(ll v, int id){
    st[id].tag += v;
    st[id].mx += v;
    st[id].mn += v;
    st[id].lm += -v;
    st[id].mr += -v;
}

void push(int id){
    addtag(st[id].tag, lc);
    addtag(st[id].tag, rc);
    st[id].tag = 0;
}

void modify(int l, int r, ll v, int L = 1, int R = 2 * n - 1, int id = 0){
    if(l <= L && R <= r){
        addtag(v, id);
        return;
    }
    push(id);
    int M = (L + R) / 2;
    if(r <= M) modify(l, r, v, L, M, lc);
    else if(l > M) modify(l, r, v, M + 1, R, rc);
    else{
        modify(l, r, v, L, M, lc);
        modify(l, r, v, M + 1, R, rc);
    }
    pull(id);
}

vector<vector<pii>> g;
vector<ll> w;
vector<int> ev, in, out;
int ts = 0;

void init(){
    st.resize(4 * (2 * n - 1));
    g.resize(n + 1);
    w.resize(n);
    ev.resize(n);
    in.resize(n + 1);
    out.resize(n + 1);
}

void dfs(int now, int p, int eid){
    if(eid != -1) ev[eid] = now;
    in[now] = ++ts;
    for(pii i : g[now]){
        if(i.F == p) continue;
        dfs(i.F, now, i.S);
        ++ts;
    }
    out[now] = ts;
}

int main(){
    StarBurstStream

    cin >> n >> q >> W;
    init();
    
    for(int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v >> w[i];
        g[u].eb(mp(v, i));
        g[v].eb(mp(u, i));
    }

    dfs(1, 1, -1);

    for(int i = 1; i <= n - 1; i++){
        int v = ev[i];
        modify(in[v], out[v], w[i]);
    }

    ll lst = 0;
    while(q--){
        ll id, tw;
        cin >> id >> tw;
        id = (id + lst) % (n - 1) + 1;
        tw = (tw + lst) % W;
        //cerr << "query " << id << " " << tw << "\n";
        int v = ev[id];
        modify(in[v], out[v], -w[id] + tw);
        w[id] = tw;
        cout << st[0].lmr << "\n";
        lst = st[0].lmr;
    }

    return 0;
}