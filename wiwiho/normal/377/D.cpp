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
    int l = -1, r = -1;
    int v = 0, tag = 0;
    int rv(){
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
    st[id].v = max(st[st[id].l].rv(), st[st[id].r].rv());
}

int query(int L, int R, int id){
    if(L == R) return L;
    int M = (L + R) / 2;
    if(st[st[id].l].rv() > st[st[id].r].rv()) return query(L, M, st[id].l);
    else return query(M + 1, R, st[id].r);
}

int main(){
    StarBurstStream

    int n;
    cin >> n;
    int mxt = 3e5+5;

    vector<vector<pair<int, pii>>> e(mxt);

    vector<int> l(n + 1), r(n + 1), v(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> v[i] >> r[i];
        e[v[i]].eb(mp(1, mp(l[i], v[i])));
        e[r[i] + 1].eb(mp(-1, mp(l[i], v[i])));
    }

    st.resize(mxt * 2);
    build(1, mxt);
    int ans = 0;
    pii ansp = mp(0, 0);
    for(int i = 1; i < mxt; i++){
        for(auto j : e[i]){
            if(j.F == 1){
                modify(j.S.F, j.S.S, 1, 1, mxt, 0);
            }
            else{
                modify(j.S.F, j.S.S, -1, 1, mxt, 0);
            }
        }
        if(st[0].rv() > ans){
            ans = st[0].rv();
            ansp = mp(query(1, mxt, 0), i);
        }
    }

    cout << ans << "\n";

    int x = ansp.F, y = ansp.S;
    for(int i = 1; i <= n; i++){
        if(l[i] <= x && x <= v[i] && v[i] <= y && y <= r[i]){
            cout << i << " ";
        }
    }
    cout << "\n";

    return 0;
}