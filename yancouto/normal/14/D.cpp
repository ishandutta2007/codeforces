#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

vector<int> adj[209];
int memo[203][203];
int dfsh(int u, int p) {
        if(memo[u][p]) return memo[u][p];
        int d = 0;
        for(int v : adj[u])
                if(v != p)
                        d = max(dfsh(v, u) + 1, d);
        return memo[u][p] = d;
}

int memo2[203][203];
int seen[203][203];
int dfs(int u, int p) {
        if(seen[u][p]) return memo2[u][p];
        seen[u][p] = 1;
        int mx = 0;
        vector<int> vv;
        for(int v : adj[u])
                if(p != v) {
                        vv.pb(dfsh(v, u) + 1);
                        mx = max(mx, dfs(v, u));
                }
        vv.pb(0);
        vv.pb(0);
        sort(vv.begin(), vv.end(), greater<int>());
        return memo2[u][p] = max(mx, vv[0] + vv[1]);
}

int main() {
        int n, i, a, b;
        scanf("%d", &n);
        for(i = 0; i < n - 1; i++) {
                scanf("%d %d", &a, &b); a--; b--;
                adj[a].pb(b); adj[b].pb(a);
        }
        int mx = 0;
        for(i = 0; i < n; i++)
                for(int v : adj[i])
                        mx = max(mx, dfs(v, i) * dfs(i, v));
        printf("%d\n", mx);
}