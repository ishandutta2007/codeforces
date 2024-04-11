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

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

struct Node{
    int l = -1, r = -1, v = 0;
};

vector<Node> st(4000000);
int ts = 0;

int build(int l, int r){
    int id = ts++;
    if(l == r) return id;
    int m = (l + r) / 2;
    st[id].l = build(l, m);
    st[id].r = build(m + 1, r);
    return id;
}

void modify(int x, int v, int L, int R, int id){
    if(L == R){
        st[id].v += v;
        return;
    }
    int M = (L + R) / 2;
    if(x <= M) modify(x, v, L, M, st[id].l);
    else modify(x, v, M + 1, R, st[id].r);
    st[id].v = st[st[id].l].v + st[st[id].r].v;
}

int query(int l, int r, int L, int R, int id){
    if(L == l && r == R){
        return st[id].v;
    }
    int M = (L + R) / 2;
    if(r <= M) return query(l, r, L, M , st[id].l);
    else if(l > M) return query(l, r, M + 1, R, st[id].r);
    else{
        return query(l, M, L, M, st[id].l) + query(M + 1, r, M + 1, R, st[id].r);
    }
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<pii> h(1000001, mp(-1, -1));
    vector<vector<pii>> hp(1000002);
    for(int i = 0; i < n; i++){
        int y, lx, rx;
        cin >> y >> lx >> rx;
        h[y] = mp(lx, rx);
    }
    h[0] = mp(0, 1000000);
    h[1000000] = mp(0, 1000000);
    for(int i = 0; i <= 1000000; i++){
        if(h[i] == mp(-1, -1)) continue;
        int y = i, lx = h[i].F, rx = h[i].S;
        hp[lx].eb(mp(1, y));
        hp[rx + 1].eb(mp(-1, y));
    }

    vector<pii> v(1000001, mp(-1, -1));
    for(int i = 0; i < m; i++){
        int x, ly, ry;
        cin >> x >> ly >> ry;
        v[x] = mp(ly, ry);
    }
    v[0] = mp(0, 1000000);
    v[1000000] = mp(0, 1000000);

    set<int> tmp;
    vector<vector<pii>> vp(1000002);
    for(int i = 0; i <= 1000000; i++){
        for(auto j : hp[i]){
            if(j.F == 1) tmp.insert(j.S);
            else tmp.erase(j.S);
        }
        if(v[i] == mp(-1, -1) || v[i].F == 0) continue;
//        printv(tmp, cerr);
        v[i].F = *tmp.lower_bound(v[i].F);
    }

    for(int i = 0; i <= 1000000; i++){
        if(v[i] == mp(-1, -1)) continue;
        vp[v[i].F].eb(mp(1, i));
        vp[v[i].S].eb(mp(-1, i));
    }

    build(0, 1000000);
    ll ans = 0;
    for(int i = 0; i <= 1000000; i++){
        if(h[i] != mp(-1, -1) && i){
//            cerr << "test " << i << "  ";
//            for(int j = 0; j <= 5; j++) cerr << query(j, j, 0, 1000000, 0) << " ";
//            cerr << "\n";
            ans += query(h[i].F, h[i].S, 0, 1000000, 0) - 1;
//            cerr << i << " " << h[i] << " " << query(h[i].F, h[i].S, 0, 1000000, 0) << " " << ans << "\n";
        }
        for(auto j : vp[i]){
//            cerr << j << "\n";
            modify(j.S, j.F, 0, 1000000, 0);
        }
    }

    cout << ans << "\n";

    return 0;
}