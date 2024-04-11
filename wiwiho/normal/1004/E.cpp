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
const ll MAX = 1LL << 60;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

bool check(int n, int k, vector<vector<pll>>& g, ll mx){
    vector<int> deg(n + 1);
    for(int i = 1; i <= n; i++) deg[i] = g[i].size();
    vector<ll> dpt(n + 1);
    vector<bool> del(n + 1);

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 1) q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        bool ok = true;
        for(pll i : g[now]){
            if(del[i.F]) continue;
            if(i.S + dpt[now] > mx) ok = false;
        }
        if(!ok) continue;
        del[now] = true;
        for(pll i : g[now]){
            if(del[i.F]) continue;
            dpt[i.F] = max(dpt[i.F], i.S + dpt[now]);
            deg[i.F]--;
            if(deg[i.F] == 1) q.push(i.F);
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(del[i]) continue;
        if(deg[i] > 2) return false;
        cnt++;
    }
    return cnt <= k;
}

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    vector<vector<pll>> g(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(mp(v, w));
        g[v].eb(mp(u, w));
    }

    ll l = 0, r = 1000000000;
    while(l < r){
        ll m = (l + r) / 2;
        if(check(n, k, g, m)) r = m;
        else l = m + 1;
    }
    cout << l << "\n";

    return 0;
}