#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
#define X first
#define Y second

const int N = 2e6 + 10;


vector<int> adj[N];


int n, a[N];
int pos[N];
int phase[N];
int mark[N];

void build(int node, int L, int R) {
    phase[node] = 0;
    mark[node] = 0;
    adj[node].clear();
    if (L == R) {
        pos[L] = node;
        return;
    }
    int mid = (L + R) / 2; 
    build(node * 2, L, (L + R) / 2);
    build(node * 2 + 1, (L + R) / 2 + 1, R);

    adj[node].push_back(node * 2);
    adj[node].push_back(node * 2 + 1);
}
void addEdge(int node, int L, int R, int l, int r, int from) {
    if (L > r || R < l) return;
    if (l <= L && R <= r) {
        adj[from].push_back(node);
        return;
    }
    int mid = (L + R) / 2;
    addEdge(node * 2, L, mid, l, r, from);
    addEdge(node * 2 + 1, mid + 1, R, l, r, from);
}
bool DFScheck(int u) {
    phase[u] = 1;
    for(auto v : adj[u]) {
        if (phase[v] == 1) return 0;
        if (phase[v] == 0) {
            if (!DFScheck(v)) return 0;
        }
    }
    phase[u] = 2;
    return 1;
}
void DFS(int &num, int u) {
    for(auto v : adj[u]) if (!mark[v]) {
        DFS(num, v);
    }
    mark[u] = ++num;
}
int ans[N];
void solve() {
    build(1, 1, n + 1); 
    for(int i = 1; i <= n; i++) if (a[i] != -1) {
        adj[pos[a[i]]].push_back(pos[i]);
        //cout << i + 1 << " " << a[i] - 1 << '\n';
        addEdge(1, 1, n + 1, i + 1, a[i] - 1, pos[i]); 
    }
    //for(int i = 0; i < N; i++) 
        //for(auto j : adj[i]) cout << i << "->" << j << '\n';
    if (!DFScheck(1)) {
        cout << "-1\n";
        return;
    }
    int num = 0;
    DFS(num, 1);

    vector<ii> res;
    for(int i = 1; i <= n; i++) res.push_back(ii(mark[pos[i]], i));
    sort(res.begin(), res.end());
    for(int i = 1; i <= n; i++) 
        ans[res[i - 1].second] = i;
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test; 
    while (test--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
            
        solve();
        
    }
}