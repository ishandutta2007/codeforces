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

int n;
vector<vector<int>> g;
vector<int> in, val;
vector<vector<int>> dpt;

struct Node{
    vector<int> mn, mx;
    Node(): mn(2, MAX), mx(2, -1) {}

    void add(int v){
        if(v == -1 || v == MAX) return;
        int tv = v;
        for(int i = 0; i < 2; i++){
            if(tv < mn[i]) swap(tv, mn[i]);
            else if(tv == mn[i]) break;
        }
        tv = v;
        for(int i = 0; i < 2; i++){
            if(tv > mx[i]) swap(tv, mx[i]);
            else if(tv == mx[i]) break;
        }
    }
};

ostream& operator<<(ostream& o, Node a){
    return o << '(' << a.mn[0] << ',' << a.mn[1] << ';' << a.mx[0] << ',' << a.mx[1] << ')';
}

vector<Node> st;

void mrg(Node& a, Node& b, Node& c){
    c = a;
    for(int i = 0; i < 2; i++) c.add(b.mn[i]);
    for(int i = 0; i < 2; i++) c.add(b.mx[i]);
}

void mrg(int a, int b, int c){
    mrg(st[a], st[b], st[c]);
}

void build(int l = 1, int r = n, int id = 0){
    if(l == r){
        st[id].add(in[l]);
        //cerr << "build " << l << " " << r << " " << st[id] << "\n";
        return;
    }
    int m = (l + r) / 2;
    build(l, m, 2 * id + 1);
    build(m + 1, r, 2 * id + 2);
    mrg(2 * id + 1, 2 * id + 2, id);
    //cerr << "build " << l << " " << r << " " << st[id] << "\n";
}

Node query(int l, int r, int L = 1, int R = n, int id = 0){
    if(l <= L && R <= r) return st[id];
    int M = (L + R) / 2;
    if(r <= M) return query(l, r, L, M, 2 * id + 1);
    else if(l > M) return query(l, r, M + 1, R, 2 * id + 2);
    else{
        Node tmp;
        Node a = query(l, r, L, M, 2 * id + 1);
        Node b = query(l, r, M + 1, R, 2 * id + 2);
        mrg(a, b, tmp);
        return tmp;
    }
}

int ts = 1;
void dfs(int now, int d){
    dpt[0][ts] = d;
    val[ts] = now;
    in[now] = ts++;
    for(int i : g[now]){
        dfs(i, d + 1);
        val[ts] = now;
        dpt[0][ts] = d;
        ts++;
    }
}

int main(){
    StarBurstStream

    int q;
    cin >> n >> q;
    g.resize(n + 1);
    in.resize(n + 1);
    dpt.resize(20, vector<int>(2 * n + 1));
    val.resize(2 * n + 1);

    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        g[p].eb(i);
    }

    dfs(1, 0);

    st.resize(4 * n);
    build();

    for(int i = 1; i < 20; i++){
        for(int j = 1; j + (1 << i) - 1 <= 2 * n; j++){
            dpt[i][j] = min(dpt[i - 1][j], dpt[i - 1][j + (1 << (i - 1))]);
        }
    }

    auto qryst = [&](int l, int r){
        int lg = __lg(r - l + 1);
        return min(dpt[lg][l], dpt[lg][r - (1 << lg) + 1]);
    };

    //printv(in, cerr);
    //printv(dpt[0], cerr);


    while(q--){
        int l, r;
        cin >> l >> r;

        Node tmp = query(l, r);
        //cerr << tmp << "\n";

        int a1 = qryst(tmp.mn[1], tmp.mx[0]);
        int a2 = qryst(tmp.mn[0], tmp.mx[1]);
        if(a1 > a2){
            cout << val[tmp.mn[0]] << " " << a1 << "\n";
        }
        else{
            cout << val[tmp.mx[0]] << " " << a2 << "\n";
        }
    }

    return 0;
}