
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

struct Node{
    pii v, tag;
    pii rv(){
        return min(v, tag);
    }
};

vector<Node> st;
int sz;
int n, m;

void push(int id){
    st[2 * id + 1].tag = min(st[2 * id + 1].tag, st[id].tag);
    st[2 * id + 2].tag = min(st[2 * id + 2].tag, st[id].tag);
    st[id].v = st[id].rv();
    st[id].tag = mp(n, 0);
}

void modify(int l, int r, pii v, int L = 0, int R = sz - 1, int id = 0){
//    cerr << "modify " << l << " " << r << " " << v << " " << L << " " << R << " " << id << "\n";
    if(l == L && r == R){
        st[id].tag = min(st[id].tag, v);
        return;
    }
    push(id);
    int M = (L + R) / 2;
    if(r <= M) modify(l, r, v, L, M, 2 * id + 1);
    else if(l > M) modify(l, r, v, M + 1, R, 2 * id + 2);
    else{
        modify(l, M, v, L, M, 2 * id + 1);
        modify(M + 1, r, v, M + 1, R, 2 * id + 2);
    }
    st[id].v = min(st[2 * id + 1].rv(), st[2 * id + 2].rv());
}

pii query(int l, int r, int L = 0, int R = sz - 1, int id = 0){
    if(l == L && r == R) return st[id].rv();
    push(id);
    int M = (L + R) / 2;
    if(r <= M) return query(l, r, L, M, 2 * id + 1);
    else if(l > M) return query(l, r, M + 1, R, 2 * id + 2);
    else{
        return min(query(l, M, L, M, 2 * id + 1), query(M + 1, r, M + 1, R, 2 * id + 2));
    }
}

int main(){
    StarBurstStream

    cin >> n >> m;

    vector<vector<pii>> seg(n + 1);
    vector<int> discr;
    for(int i = 0; i < m; i++){
        int id, l, r;
        cin >> id >> l >> r;
        discr.eb(l);
        discr.eb(r);
        seg[id].eb(mp(l, r));
    }

    lsort(discr);
    sz = discr.size();
    st.resize(sz * 4, Node({mp(n, 0), mp(n, 0)}));
//    for(int j = 0; j < sz; j++) cerr << query(j, j) << " ";
//    cerr << "\n";

    pii mn = mp(n, 0);
    vector<pii> dp(n + 1, mp(n, 0));
    for(int i = 1; i <= n; i++){
        for(pii s : seg[i]){
            int l = lower_bound(iter(discr), s.F) - discr.begin();
            int r = lower_bound(iter(discr), s.S) - discr.begin();
//            cerr << "seg " << l << " " << r << " " << query(l, r) << "\n";
            dp[i] = min(dp[i], query(l, r));
        }
        dp[i].F--;
        for(pii s : seg[i]){
            int l = lower_bound(iter(discr), s.F) - discr.begin();
            int r = lower_bound(iter(discr), s.S) - discr.begin();
            modify(l, r, mp(dp[i].F, i));
        }
        mn = min(mn, mp(dp[i].F, i));
//        cerr << "test " << i << " " << dp[i] << "\n";
//        for(int j = 0; j < sz; j++) cerr << query(j, j) << " ";
//        cerr << "\n";
    }

    vector<bool> ans(n + 1, true);
    while(mn.S != 0){
//        cerr << mn << "\n";
        ans[mn.S] = false;
        mn = dp[mn.S];
    }
//    printv(ans, cerr);
    vector<int> owo;
    for(int i = 1; i <= n; i++) if(ans[i]) owo.eb(i);
    cout << owo.size() << "\n";
    printv(owo, cout);

    return 0;
}