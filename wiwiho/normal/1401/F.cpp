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
    ll v = 0;
    int l = -1, r = -1;
};

vector<ll> a;
vector<Node> st;
int ts = 0;

int build(int l, int r){
    int id = ts++;
    if(l == r){
        st[id].v = a[l];
        return id;
    }
    int m = (l + r) / 2;
    st[id].l = build(l, m);
    st[id].r = build(m + 1, r);
    st[id].v = st[st[id].l].v + st[st[id].r].v;
    return id;
}

void modify(ll v, int x, int L, int R, int id){
    if(L == R){
        st[id].v = v;
        return;
    }
    int M = (L + R) / 2;
    if(x <= M) modify(v, x, L, M, st[id].l);
    else modify(v, x, M + 1, R, st[id].r);
    st[id].v = st[st[id].l].v + st[st[id].r].v;
}

ll query(int l, int r, int L, int R, int id){
    if(l == L && r == R) return st[id].v;
    int M = (L + R) / 2;
    if(r <= M) return query(l, r, L, M, st[id].l);
    else return query(l, r, M + 1, R, st[id].r);
}

int n;

ll qry(int l, int r, int L, int R, int x){
    if(l == L && r == R){
        int k = __lg(r - l + 1);
        int tmp = x & ~((1 << k) - 1);
        return query(l ^ tmp, r ^ tmp, 0, (1LL << n) - 1, 0);
    }
    int M = (L + R) / 2;
    if(r <= M) return qry(l, r, L, M, x);
    else if(l > M) return qry(l, r, M + 1, R, x);
    else{
        return qry(l, M, L, M, x) + qry(M + 1, r, M + 1, R, x);
    }
}

int main(){
    StarBurstStream

    int q;
    cin >> n >> q;

    a.resize(1 << n);
    st.resize(1 << (n + 1));

    for(int i = 0; i < (1 << n); i++) cin >> a[i];

    build(0, (1 << n) - 1);
    int x = 0;

    while(q--){

        int t;
        cin >> t;

        if(t == 1){
            int p, v;
            cin >> p >> v;
            p--;
            modify(v, p ^ x, 0, (1 << n) - 1, 0);
        }
        else if(t == 2){
            int k;
            cin >> k;
            x ^= (1 << k) - 1;
        }
        else if(t == 3){
            int k;
            cin >> k;
            x ^= 1 << k;
        }
        else{
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << qry(l, r, 0, (1 << n) - 1, x) << "\n";
        }

//        for(int i = 0; i < (1 << n); i++) cerr << qry(i, i, 0, (1<< n) - 1, x) << " ";
//        cerr << "\n";

    }

    return 0;
}