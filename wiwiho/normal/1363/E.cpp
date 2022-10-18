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

vector<ll> a, b, c;
vector<vector<int>> g;
ll ans = 0;

pii dfs(int now, int p){
    pii t = mp(b[now] == 0 && c[now] == 1, b[now] == 1 && c[now] == 0);
    for(int i : g[now]){
        if(i == p) continue;
        a[i] = min(a[i], a[now]);
        pii tmp = dfs(i, now);
        t.F += tmp.F;
        t.S += tmp.S;
    }
    int mn = min(t.F, t.S);
//    cerr << now << " " << mn << " " << a[now] << " " << t << "\n";
    ans += mn * 2 * a[now];
    t.F -= mn; t.S -= mn;
//    cerr << now << " " << mn << " " << a[now] << " " << t << "\n";
    return t;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    a.resize(n + 1);
    b.resize(n + 1);
    c.resize(n + 1);
    g.resize(n + 1);

    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    if(dfs(1, 1) != mp(0, 0)) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}