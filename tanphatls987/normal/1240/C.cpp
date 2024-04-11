#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, ll> pll;

#define X first
#define Y second

const int N = 5e5 + 10;

int n, k;
vector<ii> adj[N];

int q[N];
ll pa[N], pw[N];

ll f[N][2];
void BFS() {
    int top = 1, bot = 1;
    q[1] = 1;
    while (top <= bot) {
        int u = q[top++];
        for(auto i : adj[u]) {
            int v = i.first; 
            if (v == pa[u]) continue;
            pa[v] = u, pw[v] = i.second;
            q[++bot] = v;
        }
    }
}
ll solve() {
    BFS();


    for(int j = n; j >= 1; j--) {
        int u = q[j];
        f[u][0] = f[u][1] = 0;
        
        vector<pll> can;
        for(auto i : adj[u]) {
            int v = i.first;
            if (v == pa[u]) continue;
            ll fv0 = f[v][0] + pw[v];
            ll fv1 = f[v][1];
            can.push_back(pll(max(fv0 - fv1, 0LL), fv1));
        }
        sort(can.begin(), can.end());
       
        for(int i = 1; i <= can.size(); i++) {
            pll cur = can[can.size() - i];
            for(int z = 0; z <= 1; z++) {
                f[u][z] += cur.Y;   
                if (i <= k - 1 + z) f[u][z] += cur.X;
            }
        }
        //cout << u << " " << f[u][0] << " " << f[u][1] << '\n';
    }
    return f[1][1];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;

    cin >> test;
    while (test--) {
        cin >> n >> k;

        for(int i = 1; i <= n; i++) adj[i].clear();
        for(int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(ii(v, w));
            adj[v].push_back(ii(u, w));
        }

        cout << solve() << '\n';
    }

}