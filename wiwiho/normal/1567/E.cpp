
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0);
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

struct Node{
    ll lc = 0, mc = 0, rc = 0, sz = 0;
};

ll calc(ll n){
    return (n + 1) * (n) / 2;
}

ll calc(Node n){
    if(n.sz == n.lc) return calc(n.sz);
    return n.mc + calc(n.lc) + calc(n.rc);
}

Node pull(Node ln, Node rn){
    Node t;
    t.sz = ln.sz + rn.sz;
    if(ln.lc == ln.sz && rn.rc == rn.sz){
        t.lc = t.rc = t.sz;
    }
    else if(ln.lc == ln.sz){
        t.lc = ln.sz + rn.lc;
        t.rc = rn.rc;
        t.mc = rn.mc;
    }
    else if(rn.rc == rn.sz){
        t.lc = ln.lc;
        t.rc = ln.rc + rn.sz;
        t.mc = ln.mc;
    }
    else{
        t.lc = ln.lc;
        t.rc = rn.rc;
        t.mc = ln.mc + rn.mc + calc(ln.rc + rn.lc);
    }
    return t;
}

vector<Node> st;

void build(int l, int r, int id){
    st[id].sz = r - l + 1;
    if(l == r) return;
    int m = (l + r) / 2;
    build(l, m, 2 * id + 1);
    build(m + 1, r, 2 * id + 2);
}

void modify(int x, int v, int L, int R, int id){
    if(L == R){
        st[id].lc = st[id].rc = v;
        return;
    }
    int M = (L + R) / 2;
    if(x <= M) modify(x, v, L, M, 2 * id + 1);
    else modify(x, v, M + 1, R, 2 * id + 2);
    st[id] = pull(st[2 * id + 1], st[2 * id + 2]);
}

Node query(int l, int r, int L, int R, int id){
    if(l == L && r == R) return st[id];
    int M = (L + R) / 2;
    if(r <= M) return query(l, r, L, M, 2 * id + 1);
    else if(l > M) return query(l, r, M + 1, R, 2 * id + 2);
    else return pull(query(l, M, L, M, 2 * id + 1), query(M + 1, r, M + 1, R, 2 * id + 2));
}

void _print(int l, int r, int id){
    cerr << "(" << l << "," << r << "," << id << ":" << st[id].lc << "," << st[id].mc << "," << st[id].rc << ") ";
    if(l == r) return;
    int m = (l + r) / 2;
    _print(l, m, 2 * id + 1);
    _print(m + 1, r, 2 * id + 2);
}

void print(int l, int r, int id){
    _print(l, r, id);
    cerr << "\n";
}

int main(){
    StarBurstStream
    freopen("test.txt", "w", stderr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    st.resize(4 * n);
    if(n > 1) build(1, n - 1, 0);

    for(int i = 1; i < n; i++){
        modify(i, a[i] <= a[i + 1], 1, n - 1, 0);
    }

    while(q--){
//        print(1, n - 1, 0);

        int t;
        cin >> t;

        if(t == 1){
            int x, y;
            cin >> x >> y;
            a[x] = y;
            if(x > 1) modify(x - 1, a[x - 1] <= a[x], 1, n - 1, 0);
            if(x < n) modify(x, a[x] <= a[x + 1], 1, n - 1, 0);
            continue;
        }

        int l, r;
        cin >> l >> r;
        if(l == r){
            cout << "1\n";
            continue;
        }

        r--;
        Node tmp = query(l, r, 1, n - 1, 0);
//        cerr << calc(tmp) << " " << r - l + 2 << "\n";
        cout << calc(tmp) + r - l + 2 << "\n";

    }

    return 0;
}