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
vector<int> a;

pii unionrange(pii a, pii b){
    int l = min(a.F, b.F), r = max(a.S, b.S);
    return mp(l, r);
}

#define lc 2 * id + 1
#define rc 2 * id + 2

struct SegmentTree{
    vector<pii> st;

    pii _query(int l, int r, int L = 1, int R = n - 1, int id = 0){
        if(l <= L && R <= r) return st[id];
        int M = (L + R) / 2;
        if(r <= M) return _query(l, r, L, M, lc);
        else if (l > M) return _query(l, r, M + 1, R, rc);
        else return unionrange(_query(l, r, L, M, lc), _query(l, r, M + 1, R, rc));
    }

    pii query(int l, int r){
        if(l == r) return mp(1, 1);
        if(r - l + 1 == n) return mp(1, n);
        return _query(l, r - 1);
    }
};

vector<SegmentTree> st;

pii getnext(int l, int r){
    int mn = min(a[l], a[r]), mx = max(a[l], a[r]);
    return mp(mn, mx);
}

void build(int k, int L = 1, int R = n - 1, int id = 0){
    if(L > R) return;
    if(L == R){
        if(k == 0) st[k].st[id] = getnext(L, L + 1);
        else{
            pii tmp = st[k - 1].st[id];
            st[k].st[id] = st[k - 1].query(tmp.F, tmp.S);
        }
        //cerr << "build " << k << " " << L << " " << st[k].st[id] << "\n";
        return;
    }
    int M = (L + R) / 2;
    build(k, L, M, lc);
    build(k, M + 1, R, rc);
    st[k].st[id] = unionrange(st[k].st[lc], st[k].st[rc]);
}

int len(pii a){
    return a.S - a.F + 1;
}

int main(){
    StarBurstStream

    int q;
    cin >> n >> q;
    a.resize(n + 1);
    st.resize(34);
    
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i < 34; i++){
        st[i].st.resize(4 * n);
        build(i);
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        if(l == 1 && r == n){
            cout << "0\n";
            continue;
        }
        if(l == r){
            cout << "-1\n";
            continue;
        }
        //cerr << "query " << l << " " << r << "\n";

        ll ans = 0;
        for(int i = 33; i >= 0; i--){
            pii t = st[i].query(l, r);
            if(len(t) == n) continue;
            tie(l, r) = t;
            //cerr << i << " " << t << "\n";
            ans += 1LL << i;
        }
        if(r - l + 1 != n) tie(l, r) = st[0].query(l, r), ans++;
        if(r - l + 1 != n) cout << "-1\n";
        else cout << ans << "\n";
    }

    return 0;
}