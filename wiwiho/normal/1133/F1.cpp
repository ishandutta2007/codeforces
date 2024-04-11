//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cerr.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
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
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 10007;
const ll MAX = 1LL << 60;

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<int> deg(n + 1);
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        deg[u]++; deg[v]++;
        g[u].pb(v); g[v].pb(u);
    }
    int root = 1;
    for(int i = 2; i <= n; i++) if(deg[i] > deg[root]) root = i;

    queue<int> q;
    q.push(root);
    vector<bool> visit(n + 1);
    visit[root] = true;
    vector<pii> ans;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i : g[now]){
            if(visit[i]) continue;
            visit[i] = true;
            ans.pb(mp(now, i));
            q.push(i);
        }
    }

    for(pii p : ans){
        cout << p.F << " " << p.S << "\n";
    }

    return 0;
}