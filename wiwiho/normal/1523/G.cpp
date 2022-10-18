
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

struct MQ{
    map<int, int> m;
    int query(int y){
        auto it = m.upper_bound(y);
        if(it == m.begin()) return MAX;
        else return prev(it)->S;
    }
    void add(int y, int v){
        if(query(y) <= v) return;
        auto it = m.lower_bound(y);
        while(it != m.end() && it->S >= v){
            it = m.erase(it);
        }
        m[y] = v;
    }
};

int lowbit(int x){
    return x & -x;
}

int n;

struct BIT{
    vector<MQ> bit;

    void modify(int x, int y, int v){
        x = n - x + 1;
        for(; x < bit.size(); x += lowbit(x)){
            bit[x].add(y, v);
        }
    }

    int query(int x, int y){
        x = n - x + 1;
        int ans = MAX;
        for(; x > 0; x -= lowbit(x)){
            ans = min(ans, bit[x].query(y));
        }
        return ans;
    }
};

BIT bit;
vector<pii> seg;
vector<vector<int>> id;

int cnt = 0;

void dfs(int l, int r){
    if(l > r) return;
    int nxt = bit.query(l, r);
    if(nxt == MAX) return;
//    cerr << l << " " << r << " " << nxt << " " << seg[nxt] << "\n";
    cnt += seg[nxt].S - seg[nxt].F + 1;
    dfs(l, seg[nxt].F - 1);
    dfs(seg[nxt].S + 1, r);
}

int main(){
    StarBurstStream

    int m;
    cin >> n >> m;

    bit.bit.resize(n + 1);
    id.resize(n + 1);
    seg.resize(m + 1);

    for(int i = 1; i <= m; i++){
        cin >> seg[i].F >> seg[i].S;
        id[seg[i].S - seg[i].F + 1].eb(i);
    }

    vector<int> ans(n + 1);
    for(int k = n; k >= 1; k--){

        for(int i : id[k]){
            bit.modify(seg[i].F, seg[i].S, i);
        }
//        cerr << "test " << k << "\n";

        cnt = 0;
        dfs(1, n);
        ans[k] = cnt;
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}