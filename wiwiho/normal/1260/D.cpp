//#define NDEBUG

#include <bits/stdc++.h>

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
#define B back()
#define FR front()
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)
#define iceil(a) ((int)ceil(a))
#define ifloor(a) ((int)floor(a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

#define lc(a) a * 2 + 1
#define rc(a) a * 2 + 2

struct Node{
    ll sum = 0;
    ll tag = 0;
    int size = 1;
    ll realSum(){
        return size == 1 ? (sum || tag) : (tag ? size : sum);
    }
};

typedef struct Node Node;

vector<Node> st;

void build(int l, int r, int node){
    if(l == r){
        st[node].sum = 0;
        return;
    }
    int m = (l + r) / 2;
    build(l, m, lc(node));
    build(m + 1, r, rc(node));
    st[node].sum = st[lc(node)].sum + st[rc(node)].sum;
    st[node].size = st[lc(node)].size + st[rc(node)].size;
}

void push(int node){
    if(st[node].tag == 0) return;
    st[lc(node)].tag += st[node].tag;
    st[rc(node)].tag += st[node].tag;
    st[node].sum = st[node].realSum();
    st[node].tag = 0;
}

ll query(int l, int r, int L, int R, int node){
    if(l == L && r == R) return st[node].realSum();
    push(node);
    int m = (L + R) / 2;
    if(r <= m) return query(l, r, L, m, lc(node));
    if(l > m) return query(l, r, m + 1, R, rc(node));
    return query(l, m, L, m, lc(node)) + query(m + 1, r, m + 1, R, rc(node));
}

void modify(int l, int r, int v, int L, int R, int node){
    if(L == R){
        st[node].sum += v;
        return;
    }
    if(l == L && r == R){
        st[node].tag += v;
        return;
    }
    int m = (L + R) / 2;
    if(r <= m) modify(l, r, v, L, m, lc(node));
    else if(l > m) modify(l, r, v, m + 1, R, rc(node));
    else{
        modify(l, m, v, L, m, lc(node));
        modify(m + 1, r, v, m + 1, R, rc(node));
    }
    st[node].sum = st[lc(node)].realSum() + st[rc(node)].realSum();
}

int main(){
    StarBurstStream

    int m, n, k, t;
    cin >> m >> n >> k >> t;

    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];

    vector<pair<int, pii>> trap(k);
    for(int i = 0; i < k; i++){
        int l, r, d;
        cin >> l >> r >> d;
        trap[i] = mp(d, mp(l, r));
    }

    gsort(trap);

    st.resize((n + 2) * 4);
    build(0, n + 1, 0);

    int ans = trap[0].F;
    for(int i = 0; i < k; i++){
        modify(trap[i].S.F, trap[i].S.S, 1, 0, n + 1, 0);
        //cerr << query(0, n, 0, n, 0) * 2 + n << "\n";
        if(query(0, n + 1, 0, n + 1, 0) * 2 + n + 1 > t) break;
        ans = i == k - 1 ? 0 : trap[i + 1].F;
    }

    int cnt = 0;
    for(int i : a) if(i >= ans) cnt++;

    cout << cnt << "\n";

    return 0;
}