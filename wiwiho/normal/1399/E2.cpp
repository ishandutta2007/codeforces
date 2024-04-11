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

vector<vector<pair<int, pll>>> g;
vector<vector<ll>> t;
vector<int> sz;

ll sum = 0;

void dfs(int now, int p, int c, ll w){
    int cnt = 0;
    for(auto i : g[now]){
        if(i.F == p) continue;
        cnt++;
        dfs(i.F, now, i.S.F, i.S.S);
        sz[now] += sz[i.F];
    }
    if(!cnt) sz[now]++;
    if(now != p){
        sum += w * sz[now];
        while(w > 0){
            t[c].eb((w - w / 2) * sz[now]);
            w /= 2;
        }
    }
}


int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n;
        cin >> n;

        g.clear();
        g.resize(n + 1);
        t.clear();
        t.resize(3, vector<ll>(n + 1));
        sz.clear();
        sz.resize(n + 1);
        sum = 0;

        ll s;
        cin >> s;

        for(int i = 0; i < n - 1; i++){
            int u, v, c, w;
            cin >> u >> v >> w >> c;
            g[u].eb(mp(v, mp(c, w)));
            g[v].eb(mp(u, mp(c, w)));
        }

        dfs(1, 1, 0, 0);

        gsort(t[1]);
        gsort(t[2]);
        for(int i = 1; i < t[1].size(); i++) t[1][i] += t[1][i - 1];
        for(int i = 1; i < t[2].size(); i++) t[2][i] += t[2][i - 1];
        t[1].insert(t[1].begin(), 0);
        t[2].insert(t[2].begin(), 0);
//        printv(t[1], cerr);
//        printv(t[2], cerr);
//        cerr << sum << "\n";

        ll ans = MAX;
        for(int i = 0; i < t[1].size(); i++){
            ll tmp = t[1][i];
            auto it = lower_bound(iter(t[2]), sum - tmp - s);
            if(it == t[2].end()) continue;
            int j = it - t[2].begin();
//            cerr << i << " " << j << "\n";
            ans = min(ans, i + j * 2LL);
        }

        cout << ans << "\n";

    }

    return 0;
}