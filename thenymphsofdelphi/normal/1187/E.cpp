#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long

#define fi first
#define se second
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i: a)
#define bend(a) a.begin(), a.end()
#define isz(a) (int)a.size()

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef vector <vi > vvi;
typedef vector <pii > vpii;

const int N = 2e5 + 5;

int n, ans;
vi adj[N];

int dp[N];
int subtreesize[N];

void dfs(int u, int p){
    subtreesize[u] = 1;
    Fora(v, adj[u]){
        if (v == p){
            continue;
        }
        dfs(v, u);
        subtreesize[u] += subtreesize[v];
        dp[u] += dp[v];
    }
    dp[u] += subtreesize[u];
}

void dfs2(int u, int p){
    ans = max(ans, dp[u]);
    Fora(v, adj[u]){
        if (v == p){
            continue;
        }
        subtreesize[u] -= subtreesize[v];
        dp[u] -= dp[v];
        dp[u] -= subtreesize[v];
        subtreesize[v] += subtreesize[u];
        dp[v] += dp[u];
        dp[v] += subtreesize[u];
        dfs2(v, u);
        subtreesize[v] -= subtreesize[u];
        dp[v] -= dp[u];
        dp[v] -= subtreesize[u];
        subtreesize[u] += subtreesize[v];
        dp[u] += dp[v];
        dp[u] += subtreesize[v];
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n - 1){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    dfs2(1, 1);
    cout << ans;
}