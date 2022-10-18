
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
    int l = -1, r = -1;
    int mx = 0, tag = -1;
    int rv(){
        return tag == -1 ? mx : tag;
    }
};

vector<Node> st;
int ts = 0;

int build(int l, int r){
    int id = ts++;
    if(l == r) return id;
    int m = (l + r) / 2;
    st[id].l = build(l, m);
    st[id].r = build(m + 1, r);
    return id;
}

void push(int id){
    if(st[id].tag == -1) return;
    st[st[id].l].tag = st[id].tag;
    st[st[id].r].tag = st[id].tag;
    st[id].mx = st[id].tag;
    st[id].tag = -1;
}

void modify(int l, int r, int v, int L, int R, int id){
    if(l == L && r == R){
//        cerr << "modify " << l << ' ' << r << " " << v << "\n";
        st[id].tag = v;
        return;
    }
    push(id);
    int M = (L + R) / 2;
    if(r <= M) modify(l, r, v, L, M, st[id].l);
    else if(l > M) modify(l, r, v, M + 1, R, st[id].r);
    else{
        modify(l, M, v, L, M, st[id].l);
        modify(M + 1, r, v, M + 1, R, st[id].r);
    }
    st[id].mx = max(st[st[id].l].rv(), st[st[id].r].rv());
}

int query(int l, int r, int L, int R, int id){
    if(l == L && r == R) return st[id].rv();
    push(id);
    int M = (L + R) / 2;
    if(r <= M) return query(l, r, L, M, st[id].l);
    else if(l > M) return query(l, r, M + 1, R, st[id].r);
    else return max(query(l, M, L, M, st[id].l), query(M + 1, r, M + 1, R, st[id].r));
}

void _print(int l, int r, int id){
    if(l == r){
        cerr << st[id].rv() << " ";
        return;
    }
    push(id);
    int m = (l + r) / 2;
    _print(l, m, st[id].l);
    _print(m + 1, r, st[id].r);
}

void print(int l, int r, int id){
    _print(l, r, id);
    cerr << "\n";
}

vector<vector<int>> g1, g2;
vector<int> in, out;
int gts = 0;
int cnt = 0, ans = 0;
int n;

void init(){
    g1.clear();
    g2.clear();
    in.clear();
    out.clear();
    g1.resize(n + 1);
    g2.resize(n + 1);
    in.resize(n + 1);
    out.resize(n + 1);
    cnt = ans = 0;
    gts = 0;
    ts = 0;

    st.clear();
    st.resize(2 * n);
    build(1, n);
}

void dfs2(int now){
    in[now] = ++gts;
    for(int i : g2[now]){
        dfs2(i);
    }
    out[in[now]] = gts;
}

void dfs1(int now){
    int tmp = query(in[now], out[in[now]], 1, n, 0);
//    cerr << "test " << now << " " << in[now] << " " << out[in[now]] << " " << tmp << "\n";
    if(tmp > 0 && tmp < in[now]){
        modify(tmp, out[tmp], 0, 1, n, 0);
        modify(in[now], out[in[now]], in[now], 1, n, 0);
    }
    else if(tmp == 0){
        modify(in[now], out[in[now]], in[now], 1, n, 0);
        cnt++;
    }
//    print(1, n, 0);
    ans = max(ans, cnt);

    for(int i : g1[now]){
        dfs1(i);
    }

    if(tmp > 0 && tmp < in[now]){
        modify(tmp, out[tmp], tmp, 1, n, 0);
    }
    else if(tmp == 0){
        modify(in[now], out[in[now]], 0, 1, n, 0);
        cnt--;
    }
//    cerr << "ok " << now << "\n";
//    print(1, n, 0);
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        cin >> n;
        init();

        for(int i = 2; i <= n; i++){
            int p;
            cin >> p;
            g1[p].eb(i);
        }
        for(int i = 2; i <= n; i++){
            int p;
            cin >> p;
            g2[p].eb(i);
        }

        dfs2(1);
        dfs1(1);

        cout << ans << "\n";

    }

    return 0;
}