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
    int l = -1, r = -1, v = 0;
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

int modify(int pos, int v, int L, int R, int oid){
    int id = ts++;
    st[id] = st[oid];
    if(L == R){
        st[id].v += v;
//        cerr << "modify " << L << " " << R << " " << id << " " << oid << " " << st[id].v << "\n";
        return id;
    }
    int M = (L + R) / 2;
    if(pos <= M) st[id].l = modify(pos, v, L, M, st[id].l);
    else if(pos > L) st[id].r = modify(pos, v, M + 1, R, st[id].r);
    st[id].v = st[st[id].l].v + st[st[id].r].v;
//    cerr << "modify " << L << " " << R << " " << id << " " << oid << " " << st[id].v << "\n";
    return id;
}

int query(int l, int r, int L, int R, int id){
//    cerr << "query " << l << " " << r << " " << L << " " << R << " " << id << "\n";
    if(l == L && r == R) return st[id].v;
    int M = (L + R) / 2;
    if(r <= M) return query(l, r, L, M, st[id].l);
    else if(l > M) return query(l, r, M + 1, R, st[id].r);
    else{
        return query(l, M, L, M, st[id].l) + query(M + 1, r, M + 1, R, st[id].r);
    }
}

int main(){
    StarBurstStream

    st.resize(1e7);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<deque<int>> pos(100001);
    vector<int> rt(n + 2);
    build(1, n);
    for(int i = n; i > 0; i--){
        rt[i] = modify(i, 1, 1, n, rt[i + 1]);
        pos[a[i]].ef(i);
        if(pos[a[i]].size() > k){
            int t = pos[a[i]].back();
            pos[a[i]].pob;
            rt[i] = modify(t, -1, 1, n, rt[i]);
        }
//        cerr << i << "  ";
//        for(int j = 1; j <= n; j++) cerr << query(j, j, 1, n, rt[i]) << " ";
//        cerr << "\n";
    }
//    printv(rt, cerr);

    int q;
    cin >> q;
    int last = 0;
    while(q--){
        int l, r;
        cin >> l >> r;
        l = (l + last) % n + 1;
        r = (r + last) % n + 1;
        if(l > r) swap(l, r);
        last = query(l, r, 1, n, rt[l]);
        cout << last << "\n";
    }

    return 0;
}