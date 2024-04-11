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
    int mn = 0, cnt = 1, tag = 0;
    pii rv(){
        return mp(mn + tag, cnt);
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

pii pull(pii l, pii r){
    int mn = min(l.F, r.F);
    int cnt = 0;
    if(l.F == mn) cnt += l.S;
    if(r.F == mn) cnt += r.S;
    return mp(mn, cnt);
}

void pull(int id){
    pii p = pull(st[st[id].l].rv(), st[st[id].r].rv());
    st[id].mn = p.F; st[id].cnt = p.S;
}

void modify(int l, int r, int v, int L, int R, int id){
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
    pull(id);
}

void push(int id){
    pii p = st[id].rv();
    st[st[id].l].tag += st[id].tag;
    st[st[id].r].tag += st[id].tag;
    st[id].mn = p.F;
    st[id].cnt = p.S;
    st[id].tag = 0;
}

pii query(int l, int r, int L, int R, int id){
    if(l == L && r == R) return st[id].rv();
    int M = (L + R) / 2;
    push(id);
    if(r <= M) return query(l, r, L, M, st[id].l);
    else if(l > M) return query(l, r, M + 1, R, st[id].r);
    else{
        return pull(query(l, M, L, M, st[id].l), query(M + 1, r, M + 1, R, st[id].r));
    }
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    st.resize(2 * n);
    build(1, n);

    ll ans = 0;
    vector<vector<int>> pos(n + 1, vector<int>(1));
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        int now = pos[a].size();
        pos[a].eb(i);
        modify(pos[a][now - 1] + 1, i, 1, 1, n, 0);
        if(now > 3) modify(pos[a][now - 4] + 1, pos[a][now - 3], 1, 1, n, 0);
        if(now >= 3) modify(pos[a][now - 3] + 1, pos[a][now - 2], -1, 1, n, 0);
        pii p = query(1, i, 1, n, 0);
        ans += p.F == 0 ? p.S : 0;

//        for(int i = 1; i <= n; i++) cerr << query(i, i, 1, n, 0).F << " ";
//        cerr << "\n";
    }
    cout << ans << "\n";

    return 0;
}