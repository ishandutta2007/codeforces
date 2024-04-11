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
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
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

struct Node{
    int l = -1, r = -1, len = 1;
    vector<ll> v;
    Node(){
        v.resize(4);
    }
};

vector<Node> st;

void pull(int id, int a){
    int l = st[id].l;
    int r = st[id].r;
    int tl = st[l].len == 1 ? 0 : 1;
    int tr = st[r].len == 1 ? 0 : 2;

    st[id].len = st[l].len + st[r].len;

    st[id].v[0] = st[l].v[tl] * st[r].v[tr] % MOD;
    st[id].v[1] = st[l].v[tl] * st[r].v[3] % MOD;
    st[id].v[2] = st[l].v[3] * st[r].v[tr] % MOD;
    st[id].v[3] = st[l].v[3] * st[r].v[3] % MOD;

    if(a >= 10 && a <= 19){
        tl = st[l].len == 1 ? 2 : 0;
        tr = st[r].len == 1 ? 1 : 0;
        st[id].v[tl | tr] += st[l].v[0] * st[r].v[0] % MOD * (19 - a) % MOD;
        st[id].v[tl | 1] += st[l].v[0] * st[r].v[1] % MOD * (19 - a) % MOD;
        st[id].v[2 | tr] += st[l].v[2] * st[r].v[0] % MOD * (19 - a) % MOD;
        st[id].v[3] += st[l].v[2] * st[r].v[1] % MOD * (19 - a) % MOD;
        for(int i = 0; i < 4; i++) st[id].v[i] %= MOD;
    }
}

vector<int> c;
int ts = 0;

int build(int l, int r){
    int id = ts++;
    if(l == r){
        st[id].v[0] = 1;
        st[id].v[3] = c[l] + 1;
        return id;
    }
    int m = (l + r) / 2;
    st[id].l = build(l, m);
    st[id].r = build(m + 1, r);
    pull(id, c[m] * 10 + c[m + 1]);
    return id;
}

void modify(int x, int L, int R, int id){
    if(L == R){
        st[id].v[3] = c[x] + 1;
        return;
    }
    int M = (L + R) / 2;
    if(x <= M) modify(x, L, M, st[id].l);
    else modify(x, M + 1, R, st[id].r);
    pull(id, c[M] * 10 + c[M + 1]);
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    c.resize(n);
    st.resize(2 * n);

    string tmp;
    cin >> tmp;
    for(int i = 0; i < n; i++){
        c[i] = tmp[i] - '0';
    }

    build(0, n - 1);
    for(int i = 0; i < m; i++){
        int x, d;
        cin >> x >> d;
        x--;
        c[x] = d;
        modify(x, 0, n - 1, 0);
        cout << st[0].v[3] << "\n";
    }

    return 0;
}