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

struct Node{
    ld vl = 0, vr = 0;
    int l = -1, r = -1;
};

vector<Node> st(200000);
int ts = 0;

vector<ld> p(100001);

pdd pull(pdd l, pdd r){
    ld l1 = l.F, l2 = r.F, r1 = l.S, r2 = r.S;
    return mp(l1 * l2 / (1 + r1 * (l2 - 1)),
            r2 + (r1 * l2 * (1 - r2) / (1 - r1 * (1 - l2))));
}

void pull(int id){
    ld l1 = st[st[id].l].vl;
    ld l2 = st[st[id].r].vl;
    ld r1 = st[st[id].l].vr;
    ld r2 = st[st[id].r].vr;
    st[id].vl = l1 * l2 / (1 + r1 * (l2 - 1));
    st[id].vr = r2 + (r1 * l2 * (1 - r2) / (1 - r1 * (1 - l2)));
}

int build(int l, int r){
    int id = ts++;
    if(l == r){
        st[id].vl = st[id].vr = p[l];
        return id;
    }
    int m = (l + r) / 2;
    st[id].l = build(l, m);
    st[id].r = build(m + 1, r);
    pull(id);
    return id;
}

void modify(int x, ld v, int L, int R, int id){
    if(L == R){
        st[id].vl = st[id].vr = v;
        return;
    }
    int M = (L + R) / 2;
    if(x <= M) modify(x, v, L, M, st[id].l);
    else modify(x, v, M + 1, R, st[id].r);
    pull(id);
}

pdd query(int l, int r, int L, int R, int id){
    if(L == l && R == r) return mp(st[id].vl, st[id].vr);
    int M = (L + R) / 2;
    if(r <= M) return query(l, r, L, M, st[id].l);
    else if(l > M) return query(l, r, M + 1, R, st[id].r);
    else return pull(query(l, M, L, M, st[id].l), query(M + 1, r, M + 1, R, st[id].r));
}

int main(){
    StarBurstStream

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        ld a, b;
        cin >> a >> b;
        p[i] = a / b;
    }
    build(1, n);

    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int i;
            ld a, b;
            cin >> i >> a >> b;
            modify(i, a / b, 1, n, 0);
        }
        else{
            int l, r;
            cin >> l >> r;
            pdd ans = query(l, r, 1, n, 0);
            cout << fixed << setprecision(20) << ans.F << "\n";
        }
    }

    return 0;
}