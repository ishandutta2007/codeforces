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

struct Node{
    ll mx = 0, sum = 0, l = -1, r = -1;
};

int cnt = 1;
vector<Node> st;
vector<ll> a, d;

ll D(int n){
    if(d[n] != -1) return d[n];
    d[n] = 0;
    for(int i = 1; i * i <= n; i++){
        if(i * i == n) d[n]++;
        else if(n % i == 0) d[n] += 2;
    }
//    cerr << "D " << n << " " << d[n] << "\n";
    return d[n];
}

int build(int l, int r, int id){
    if(l == r){
        st[id].mx = a[l];
        st[id].sum = a[l];
        return id;
    }
    int m = (l + r) / 2;
    st[id].l = build(l, m, cnt++);
    st[id].r = build(m + 1, r, cnt++);
    st[id].mx = max(st[st[id].l].mx, st[st[id].r].mx);
    st[id].sum = st[st[id].l].sum +  st[st[id].r].sum;
    return id;
}

void modify(int l, int r, int L, int R, int id){
    if(st[id].mx <= 2) return;
    if(L == R){
//        cerr << l << " " << D(st[id].mx) << "\n";
        st[id].mx = D(st[id].mx);
        st[id].sum = D(st[id].sum);
        return;
    }
    int M = (L + R) / 2;
    if(r <= M) modify(l, r, L, M, st[id].l);
    else if(l > M) modify(l, r, M + 1, R, st[id].r);
    else{
        modify(l, M, L, M, st[id].l);
        modify(M + 1, r, M + 1, R, st[id].r);
    }
    st[id].mx = max(st[st[id].l].mx, st[st[id].r].mx);
    st[id].sum = st[st[id].l].sum +  st[st[id].r].sum;
}

ll query(int l, int r, int L, int R, int id){
    if(l == L && r == R) return st[id].sum;
    int M = (L + R) / 2;
    if(r <= M) return query(l, r, L, M, st[id].l);
    else if(l > M) return query(l, r, M + 1, R, st[id].r);
    else{
        return query(l, M, L, M, st[id].l) + query(M + 1, r, M + 1, R, st[id].r);
    }
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    a.resize(n + 1);
    d.resize(1000001, -1);
    st.resize(4 * n);
    for(int i = 1; i <= n; i++) cin >> a[i];

    build(1, n, 0);

    while(m--){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1) modify(l, r, 1, n, 0);
        else cout << query(l, r, 1, n, 0) << "\n";
    }

    return 0;
}