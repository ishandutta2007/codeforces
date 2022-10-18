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
#define iceil(a) ((int)ceil(a))
#define ifloor(a) ((int)floor(a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

vector<vector<int>> g;
vector<int> ans;

void dfs(int now, int p){
    for(int i : g[now]){
        if(i == p) continue;
        dfs(i, now);
    }
    ans.eb(now);
    for(int i = g[now].size() - 1; i >= 0; i--)
        if(g[now][i] != p) ans.eb(g[now][i]);
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    g.resize(n + 1);
    for(int i =1 ; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    dfs(1, 1);
    ans.eb(1);
    //printv(ans, cerr);

    vector<vector<int>> s(n + 1);
    for(int i = 0; i < 2 * n; i++){
        s[ans[i]].eb(i + 1);
    }

    for(int i = 1; i <= n; i++) cout << s[i][0] << " " << s[i][1] << "\n";

    return 0;
}