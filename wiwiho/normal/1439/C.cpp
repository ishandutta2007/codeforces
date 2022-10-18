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

struct Node{
    int sz = 1;
    ll mx = 0, sum = 0, tag = 0;
    ll rmx(){
        return tag ? tag : mx;
    }
    ll rsum(){
        return tag ? tag * sz : sum;
    }
};

ostream& operator<<(ostream& o, Node n){
    return o << '(' << n.rmx() << ',' << n.rsum() << ',' << n.tag << ')';
}

vector<Node> st;
int ts = 0;

void build(int l, int r, int id){
    if(l == r) return;
    int m = (l + r) / 2;
    build(l, m, 2 * id + 1);
    build(m + 1, r, 2 * id + 2);
    st[id].sz = st[2 * id + 1].sz + st[2 * id + 2].sz;
}

void push(int id){
    if(st[id].tag){
        st[2 * id + 1].tag = st[id].tag;
        st[2 * id + 2].tag = st[id].tag;
    }
    st[id].sum = st[id].rsum();
    st[id].mx = st[id].rmx();
    st[id].tag = 0;
}

void modify(int l, int r, ll v, int L, int R, int id){
    if(l == L && r == R){
        st[id].tag = v;
        return;
    }
    push(id);
    int M = (L + R) / 2;
    if(r <= M) modify(l, r, v, L, M, 2 * id + 1);
    else if(l > M) modify(l, r, v, M + 1, R, 2 * id + 2);
    else{
        modify(l, M, v, L, M, 2 * id + 1);
        modify(M + 1, r, v, M + 1, R, 2 * id + 2);
    }
    st[id].sum = st[2 * id + 1].rsum() + st[2 * id + 2].rsum();
    st[id].mx = max(st[2 * id + 1].rmx(), st[2 * id + 2].rmx());
}

int fl(ll v, int L, int R, int id){
    if(L == R){
        if(st[id].rmx() > v) return L + 1;
        return L;
    }
    push(id);
    int M = (L + R) / 2;
    if(st[2 * id + 2].rmx() < v) return fl(v, L, M, 2 * id + 1);
    else return fl(v, M + 1, R, 2 * id + 2);
}

int fsum(ll v, int L, int R, int id){
    if(L == R){
        if(st[id].rsum() <= v) return L + 1;
        return L;
    }
    push(id);
    int M = (L + R) / 2;
    if(st[2 * id + 1].rsum() <= v) return fsum(v - st[2 * id + 1].rsum(), M + 1, R, 2 * id + 2);
    else return fsum(v, L, M, 2 * id + 1);
}

ll query(int l, int r, int L, int R, int id){
    if(l == L && r == R) return st[id].rsum();
    push(id);
    int M = (L + R) / 2;
    if(r <= M) return query(l, r, L, M, 2 * id + 1);
    else if(l > M) return query(l, r, M + 1, R, 2 * id + 2);
    else{
        return query(l, M, L, M, 2 * id + 1) + query(M + 1, r, M + 1, R, 2 * id + 2);
    }
}

int main(){
    StarBurstStream

    int n, q;
    cin >> n >> q;

    st.resize(4 * n);
    build(1, n, 0);

    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        modify(i, i, a, 1, n, 0);
    }

    while(q--){
        int t;
        cin >> t;

        if(t == 1){
            ll x, y;
            cin >> x >> y;
            int s = fl(y, 1, n, 0);
            if(s <= x) modify(s, x, y, 1, n, 0);
            continue;
        }

        ll x, y;
        cin >> x >> y;
        int ans = 0;
        while(y > 0 && x <= n){
            int s = fl(y, 1, n, 0);
            s = max(s, (int) x);
            if(s == n + 1) break;
            ll sum = s == 1 ? 0 : query(1, s - 1, 1, n, 0);
            sum += y;
            int e = fsum(sum, 1, n, 0) - 1;
            ans += e - s + 1;
            y -= query(s, e, 1, n, 0);
            x = e + 1;
        }
        cout << ans << "\n";

    }

    return 0;
}