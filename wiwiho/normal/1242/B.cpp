//#define NDEBUG

#include <bits/stdc++.h>

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
#define B back()
#define FR front()
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)
#define iceil(a) ((int)ceil((int)a))
#define ifloor(a) ((int)floor((int)a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

set<int> s;
vector<vector<int>> g;
vector<bool> visit;

void dfs(int now){
    visit[now] = true;
    vector<bool> no(g.size());
    vector<int> q;
    for(int i : g[now]) no[i] = true;
    for(int i : s) if(!no[i]) q.eb(i);
    for(int i : q) s.erase(i);
    for(int i : q) dfs(i);
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    visit.resize(n + 1);

    for(int i = 1; i <= n; i++) s.insert(i);

    for(int i =0 ; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(visit[i]) continue;
        ans++;
        dfs(i);
    }

    cout << ans - 1 << '\n';

    return 0;
}