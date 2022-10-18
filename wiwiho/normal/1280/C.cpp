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

vector<vector<pii>> g;

int k;
ll mx = 0, mn = 0;

int dfs(int now, ll e, int p){
    int sz = 1;
    for(pii i : g[now]){
        if(i.F == p) continue;
        sz += dfs(i.F, i.S, now);
    }
    mx += min(sz, 2 * k - sz) * e;
    mn += sz % 2 * e;
    return sz;
}


int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        cin >> k;

        g.clear();
        g.resize(2 * k + 1);

        for(int i = 0; i < 2 * k - 1; i++){
            int u,v ,w;
            cin >> u >> v >> w;
            g[u].eb(mp(v, w));
            g[v].eb(mp(u, w));
        }

        mx = 0; mn = 0;
        dfs(1, 0, 1);
        cout << mn << " " << mx << "\n";

    }

    return 0;
}