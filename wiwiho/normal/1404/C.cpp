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
    int l = -1, r = -1;
    ll v = MAX, tag = 0;
    ll rv(){
        return v + tag;
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

void modify(int l, int r, ll v, int L, int R, int id){
//    cerr << "modify " << l << " " << r << " " << v << " " << L << " " << R << " " << id << "\n";
    if(l == L && r == R){
        st[id].tag += v;
        return;
    }
    int M = (L + R) / 2;
    if(r <= M) modify(l, r, v, L, M, st[id].l);
    else if(l > M) modify(l, r, v, M + 1, R, st[id].r);
    else{
        modify(l, M, v, L, M, st[id].l);
        modify(M + 1, r, v, M + 1, R, st[id].r);
    }
    st[id].v = min(st[st[id].l].rv(), st[st[id].r].rv());
}

void push(int id){
    st[id].v = st[id].rv();
    st[st[id].l].tag += st[id].tag;
    st[st[id].r].tag += st[id].tag;
    st[id].tag = 0;
}

int f0(int L, int R, int id){
//    cerr << "f0 " << L << " " << R << " " << id << " " << st[id].rv() << "\n";
    if(st[id].rv() > 0) return MAX;
    if(L == R) return L;
    push(id);
    int M = (L + R) / 2;
    int tmp = f0(L, M, st[id].l);
    if(tmp != MAX) return tmp;
    else return f0(M + 1, R, st[id].r);
}

ll query(int x, int L, int R, int id){
    if(L == R) return st[id].rv();
    push(id);
    int M = (L + R) / 2;
    if(x <= M) return query(x, L, M, st[id].l);
    else return query(x, M + 1, R, st[id].r);
}

int lowbit(int x){
    return x & -x;
}

struct BIT{
    vector<int> bit;
    BIT(int sz){
        bit.resize(sz + 1);
    }
    void modify(int x, int v){
        for(; x < bit.size(); x += lowbit(x)){
            bit[x] += v;
        }
    }
    int query(int x){
        int ans = 0;
        for(; x > 0; x -= lowbit(x)){
            ans += bit[x];
        }
        return ans;
    }
};

int main(){
    StarBurstStream

    int n, q;
    cin >> n >> q;
    st.resize(2 * n);
    build(1, n);
    BIT bit(n);

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<vector<pii>> qry(n + 1);
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        qry[x].eb(mp(y, i));
    }

    vector<int> ans(q);
    for(int i = n; i >= 0; i--){
        if(i < n){
            int t = i + 1;
//            cerr << t << ' ' << a[t] << " " << t - a[t] - query(t, 1, n, 0) << "\n";
            if(t >= a[t]) modify(t, t, t - a[t] - query(t, 1, n, 0), 1, n, 0);
        }
//        cerr << i << "  ";
//        for(int j = 1; j <= n; j++) cerr << query(j, 1, n, 0) << " ";
//        cerr << "\n";
//        cerr << i << "  ";
//        for(int j = 1; j <= n; j++) cerr << bit.query(j) - bit.query(j - 1) << " ";
//        cerr << "\n";
        while(true){
            int t = f0(1, n, 0);
            if(t == MAX) break;
            modify(t, n, -1, 1, n, 0);
            modify(t, t, MAX, 1, n, 0);
            bit.modify(t, 1);
//            cerr << "test " << i << " " << t << "\n";
        }
        for(auto j : qry[i]){
            ans[j.S] = bit.query(n - j.F);
        }
    }

    for(int i : ans) cout << i << "\n";

    return 0;
}