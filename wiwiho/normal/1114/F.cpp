//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll fp(ll a, ll b){
    ll now = 1;
    ll base = a;
    while(b > 0){
        if(b & 1) now = now * base % MOD;
        base = base * base % MOD;
        b >>= 1;
    }
    return now;
}

struct NodeP{
    ll v = 1, l = -1, r = -1, tag = 1, sz = 1;
    ll rv(){
        return v * fp(tag, sz) % MOD;
    }
};

struct PT{
    vector<NodeP> st;

    int cnt = 0;

    explicit PT(int sz){
        st.resize(2 * (sz + 1));
    }

    int build(int l, int r, int id){
        if(id == -1) id = cnt++;
        if(l == r) return id;
        int m = (l + r) / 2;
        st[id].l = build(l, m, -1);
        st[id].r = build(m + 1, r, -1);
        st[id].sz = st[st[id].l].sz + st[st[id].r].sz;
        return id;
    }

    void modify(int l, int r, ll v, int L, int R, int id){
        if(l == L && r == R){
            st[id].tag *= v;
            st[id].tag %= MOD;
            return;
        }
        int M = (L + R) / 2;
        if(r <= M) modify(l, r, v, L, M, st[id].l);
        else if(l > M) modify(l, r, v, M + 1, R, st[id].r);
        else{
            modify(l, M, v, L, M, st[id].l);
            modify(M + 1, r, v, M + 1, R, st[id].r);
        }
        st[id].v = st[st[id].l].rv() * st[st[id].r].rv() % MOD;
    }

    void push(int id){
        st[st[id].l].tag = st[st[id].l].tag * st[id].tag % MOD;
        st[st[id].r].tag = st[st[id].r].tag * st[id].tag % MOD;
        st[id].v = st[id].rv();
        st[id].tag = 1;
    }

    ll query(int l, int r, int L, int R, int id){
        if(l == L && r == R) return st[id].rv();
        push(id);
        int M = (L + R) / 2;
        if(r <= M) return query(l, r, L, M , st[id].l);
        else if(l > M) return query(l, r, M + 1, R, st[id].r);
        else{
            return query(l, M, L, M, st[id].l) * query(M + 1, r, M + 1, R, st[id].r) % MOD;
        }
    }

};

struct NodeO{
    ll v = 0, l = -1, r = -1, tag = 0;
    ll rv(){
        return v | tag;
    }
};

struct OT{
    vector<NodeO> st;

    int cnt = 0;

    explicit OT(int sz){
        st.resize(2 * (sz + 1));
    }

    int build(int l, int r, int id){
        if(id == -1) id = cnt++;
        if(l == r) return id;
        int m = (l + r) / 2;
        st[id].l = build(l, m, -1);
        st[id].r = build(m + 1, r, -1);
        return id;
    }

    void modify(int l, int r, ll v, int L, int R, int id){
        if(l == L && r == R){
            st[id].tag |= v;
            return;
        }
        int M = (L + R) / 2;
        if(r <= M) modify(l, r, v, L, M, st[id].l);
        else if(l > M) modify(l, r, v, M + 1, R, st[id].r);
        else{
            modify(l, M, v, L, M, st[id].l);
            modify(M + 1, r, v, M + 1, R, st[id].r);
        }
        st[id].v = st[st[id].l].rv() | st[st[id].r].rv();
    }

    void push(int id){
        st[st[id].l].tag |= st[id].tag;
        st[st[id].r].tag |= st[id].tag;
        st[id].v = st[id].rv();
        st[id].tag = 0;
    }

    ll query(int l, int r, int L, int R, int id){
        if(l == L && r == R) return st[id].rv();
        push(id);
        int M = (L + R) / 2;
        if(r <= M) return query(l, r, L, M , st[id].l);
        else if(l > M) return query(l, r, M + 1, R, st[id].r);
        else{
            return query(l, M, L, M, st[id].l) | query(M + 1, r, M + 1, R, st[id].r);
        }
    }

};

int main(){
    StarBurstStream

    vector<int> p;
    for(int i = 2; i <= 300; i++){
        bool tmp = true;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                tmp = false;
                break;
            }
        }
        if(tmp) p.eb(i);
    }
    int cnt = p.size();

    int n, q;
    cin >> n >> q;

    PT pt(n);
    OT ot(n);

    pt.build(1, n, -1);
    ot.build(1, n, -1);

    for(int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        pt.modify(i, i, a, 1, n, 0);
        for(int j = 0; j < cnt; j++){
            if(a % p[j] == 0) ot.modify(i, i, (1LL << j), 1, n, 0);
        }
    }

//    for(int i = 1; i <= n; i++) cerr << pt.query(i, i, 1, n, 0) << " ";
//    cerr << "\n";

    while(q--){
        string s;
        cin >> s;

        if(s[0] == 'M'){
            ll l, r, x;
            cin >> l >> r >> x;
            for(int i = 0; i < cnt; i++){
                if(x % p[i] == 0) ot.modify(l, r, (1LL << i), 1, n, 0);
            }
            pt.modify(l, r, x, 1, n, 0);
            continue;
        }

        int l, r;
        cin >> l >> r;

        ll a = pt.query(l, r, 1, n, 0), b = 1;
        ll t = ot.query(l, r, 1, n, 0);

        for(int i = 0; i < cnt; i++){
            if((1LL << i & t) == 0) continue;
            a = a * (p[i] - 1) % MOD;
            b = b * p[i] % MOD;
        }

        cout << a * fp(b, MOD - 2) % MOD << "\n";
    }

    return 0;
}