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


#define lc(x) (2*(x)+1)
#define rc(x) (2*(x)+2)

struct Node{
    ll mn = 1LL << 60;
    ll tag = 0;
    ll realMin(){
        return mn + tag;
    }
};

vector<ll> a;
vector<Node> st;

void build(int l, int r, int id){
    if(l == r){
        st[id].mn = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(l, m, lc(id));
    build(m + 1, r, rc(id));
    st[id].mn = min(st[lc(id)].mn, st[rc(id)].mn);
}

void push(int id){
    st[lc(id)].tag += st[id].tag;
    st[rc(id)].tag += st[id].tag;
    st[id].mn = st[id].realMin();
    st[id].tag = 0;
}

ll query(int l, int r, int L, int R, int id){
    if(l == L && r == R) return st[id].realMin();
    int M = (L + R) / 2;
    push(id);
    if(r <= M) return query(l, r, L, M, lc(id));
    else if(l > M) return query(l, r, M + 1, R, rc(id));
    else{
        return min(query(l, M, L, M, lc(id)), query(M + 1, r, M + 1, R, rc(id)));
    }
}

void modify(int l, int r, ll v, int L, int R, int id){
    if(l == L && r == R){
        st[id].tag += v;
        return;
    }
    int M = (L + R) / 2;
    if(r <= M) modify(l, r, v, L, M, lc(id));
    else if(l > M) modify(l, r, v, M + 1, R, rc(id));
    else{
        modify(l, M, v, L, M, lc(id));
        modify(M + 1, r, v, M + 1, R, rc(id));
    }
    st[id].mn = min(st[lc(id)].realMin(), st[rc(id)].realMin());
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    a.resize(n);
    st.resize(4 * n);

    vector<int> pos(n + 1), c(n);
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        pos[t] = i;
    }

    for(int i = 0; i < n; i++){
        cin >> c[i];
        a[i] = c[i];
        if(i != 0) a[i] += a[i - 1];
    }

    build(0, n - 1, 0);

    ll ans = a[0];
    for(int i = 1; i <= n; i++){
        modify(pos[i], n - 1, -c[pos[i]], 0, n - 1, 0);
        if(pos[i] > 0) modify(0, pos[i] - 1, c[pos[i]], 0, n - 1, 0);
        ans = min(ans, query(0, n - 2, 0, n - 1, 0));
    }

    cout << ans << "\n";

    return 0;
}