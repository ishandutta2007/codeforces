#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N = 5e5 + 10;

int a[N];
int g[N];
int f[N];
int n1;
int n, h[N];
vector<int> adj[N];


bool BFS(int st) {

    queue<int> q;
    q.push(st);

    g[st] = ++n1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v : adj[u]) if (g[v] == -1) {
            g[v] = g[u];
            q.push(v);
        }
    }
    return 1;
}

void fail() {
    cout << "-1";
    exit(0);
}
void solve() {
    memset(g, -1, sizeof(g));
    for(int st = 1; st <= n; st++) if (g[st] == -1)
        if (!BFS(st)) fail();

    //for(int i = 1; i <= n; i++) cout << g[i] << " "; cout << '\n';
    int m = n1;
    memset(h, -1, sizeof(h));
    for(int i = 1; i <= n; i++) {
        if (h[g[i]] == -1) h[g[i]] = f[i];
        if (h[g[i]] != f[i]) fail();
    }

    cout << m << '\n';
    for(int i = 1; i <= n; i++) cout << g[i] << " "; cout << '\n';
    for(int i = 1; i <= m; i++) cout << h[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> f[i];

    for(int i = 1; i <= n; i++) {
        adj[i].push_back(f[i]);
        adj[f[i]].push_back(i);
    }
    solve();
}