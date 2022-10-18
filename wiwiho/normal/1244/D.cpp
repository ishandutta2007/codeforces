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
vector<int> tree;

void dfs(int n, int p){
    tree.eb(n);
    for(int i : g[n]){
        if(i == p) continue;
        dfs(i, n);
    }
}

int yee(int a, int b){
    for(int i = 0; i < 3; i++){
        if(i != a && i != b) return i;
    }
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<vector<ll>> c(3, vector<ll>(n));
    g.resize(n);
    tree.reserve(n);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++) cin >> c[i][j];
    }

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].eb(v); g[v].eb(u);
    }

    int root = -1;
    for(int i = 0; i < n; i++){
        if(g[i].size() != 1 && g[i].size() != 2) return cout << "-1\n", 0;
        if(g[i].size() == 1) root = i;
    }
    if(root == -1) return cout << "-1\n", 0;

    dfs(root, root);

    ll ans = 1LL << 60;
    vector<int> ansc(n);
    for(int f = 0; f < 3; f++){
        for(int s = 0; s < 3; s++){
            if(f == s) continue;
            vector<int> tc(n);
            tc[0] = f; tc[1] = s;
            ll tans = c[tc[0]][tree[0]] + c[tc[1]][tree[1]];
            for(int i = 2; i < n; i++){
                tc[i] = yee(tc[i - 1], tc[i - 2]);
                tans += c[tc[i]][tree[i]];
            }
            if(tans < ans){
                ans = tans;
                for(int i = 0; i < n; i++) ansc[tree[i]] = tc[i] + 1;
            }
        }
    }

    cout << ans << "\n";
    printv(ansc, cout);

    return 0;
}