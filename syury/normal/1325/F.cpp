//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

const int N = (int)2e5 + 5;

int n, m;
int sz;
bool used[N];
vector<int> gr[N];
vector<int> tr[N];
int color[N];
int h[N], p[N];
int cnt[N];

void dfs(int v, int depth = 0){
    used[v] = 1;
    h[v] = depth;
    color[v] = depth%sz;
    for(int u: gr[v])
        if(!used[u]){
            p[u] = v;
            dfs(u, depth + 1);
        }
}

void solve(){
    memset(used, 0, sizeof(used));
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        --v; --u;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    sz = int(sqrt(n) + 1e-6);
    while(sz*sz > n)--sz;
    dfs(0);
    p[0] = -1;
    for(int i = 0; i < n; i++){
        for(int j: gr[i]){
            if(color[i] == color[j]){
                vector<int> ans;
                int v = h[i] > h[j] ? i : j;
                int u = i + j - v;
                while(v != u){
                    ans.push_back(v + 1);
                    v = p[v];
                }
                ans.push_back(u + 1);
                cout << "2\n" << ans.size() << '\n';
                for(int v: ans)cout << v << ' ';
                cout << endl;
                return;
            }
        }
        ++cnt[color[i]];
    }
    int best = max_element(cnt, cnt + sz) - cnt;
    vector<int> ans;
    for(int i = 0; i < n; i++)
        if(color[i] == best)ans.push_back(i+1);
    int need = sz;
    while(need*need < n)++need;
    if(ans.size() > need)
        ans.resize(need);
    cout << "1\n";
    for(int v: ans)cout << v << ' ';
    cout << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}