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
    int l = -1, r = -1, v = 0, tag = 0;
    int rv(){
        return v + tag;
    }
};

vector<int> a;
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
    st[id].v = min(st[st[id].l].v, st[st[id].r].v);
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
    st[id].v = min(st[st[id].l].rv(), st[st[id].r].rv());
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    a.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<pii> s(m);
    for(int i = 0; i < m; i++) cin >> s[i].F >> s[i].S;

    st.resize(2 * n);
    build(1, n);

    int ans = 0;
    int pos = 1;
    for(int i = 1; i <= n; i++){

        for(int j = 0; j < m; j++){
            if(s[j].F <= i && i <= s[j].S) continue;
            modify(s[j].F, s[j].S, -1, 1, n, 0);
        }

        if(a[i] - st[0].rv() > ans){
            ans = a[i] - st[0].rv();
            pos = i;
        }

        for(int j = 0; j < m; j++){
            if(s[j].F <= i && i <= s[j].S) continue;
            modify(s[j].F, s[j].S, 1, 1, n, 0);
        }

    }

    vector<int> anss;
    for(int i = 0; i < m; i++){
        if(s[i].F <= pos && pos <= s[i].S) continue;
        anss.eb(i + 1);
    }

    cout << ans << "\n";
    cout << anss.size() << "\n";
    printv(anss, cout);

    return 0;
}