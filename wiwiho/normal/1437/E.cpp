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
#define topos(a) (((a) % MOD + MOD) % MOD)
#define uni(a) a.resize(unique(iter(a)) - a.begin())
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
const ll MAX = 100000000;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

struct Node{
    int l = -1, r = -1, v = -MAX;
};

vector<Node> st(1.8e7);
int ts = 1;

int newnode(){
//    cerr << "newnode\n";
    st[ts] = Node();
    return ts++;
}

void pull(int id){
    st[id].v = -MAX;
    if(st[id].l != -1) st[id].v = max(st[id].v, st[st[id].l].v);
    if(st[id].r != -1) st[id].v = max(st[id].v, st[st[id].r].v);
}

int modify(int x, int v, int L, int R, int id){
    if(id == -1) id = newnode();
//    cerr << "modify " << x << " " << v << " " << id << "\n";
    if(L == R){
        st[id].v = max(st[id].v, v);
        return id;
    }
    int M = L + R < 0 ? (L + R - 1) / 2 : (L + R) / 2;
    if(x <= M) st[id].l = modify(x, v, L, M, st[id].l);
    else st[id].r = modify(x, v, M + 1, R, st[id].r);
    pull(id);
    return id;
}

int query(int l, int r, int L, int R, int id){
    if(id == -1) return -MAX;
    if(l == L && r == R){
//        cerr << "query " << l << " " << r << " " << st[id].v << "\n";
        return st[id].v;
    }
    int M = L + R < 0 ? (L + R - 1) / 2 : (L + R) / 2;
    if(r <= M) return query(l, r, L, M, st[id].l);
    else if(l > M) return query(l, r, M + 1, R, st[id].r);
    else return max(query(l, M, L, M, st[id].l), query(M + 1, r, M + 1, R, st[id].r));
}

int L = -1e6, R = 1e9;

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<bool> b(n);
    for(int i = 0; i < k; i++){
        int t;
        cin >> t;
        b[t - 1] = true;
    }

    bool ok = true;
    for(int i = 0; i < n; i++){
        int tmp = query(L, a[i] - i, L, R, 0);
        if(ok) tmp = max(tmp, 0);
//        cerr << i << " " << a[i] << " " << a[i] - i << " " << tmp << "\n";
//        for(int j = -5; j <= 0; j++) cerr << query(j, j, L, R, 0) << " ";
        if(b[i]){
            ok = false;
            ts = 1;
            st[0] = Node();
        }
//        cerr << "\n";
        if(tmp != -MAX) modify(a[i] - i, tmp + 1, L, R, 0);
    }

    int ans = query(L, R, L, R, 0);
    if(ans == -MAX) ans = -1;
    else ans = n - ans;
    cout << ans << "\n";

    return 0;
}