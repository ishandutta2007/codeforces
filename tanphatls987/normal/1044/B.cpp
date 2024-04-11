#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second


const int N = 1e3 + 10;

int n;
vector<int> adj[N], imp[2];

int mark[N];
void reset() {
    for(int i = 1; i <= n; i++) adj[i].clear();
    memset(mark, 0, sizeof(mark));
}
int BFS(int st) {
    if (mark[st] == 2) return st;
    
    queue<int> q;
    q.push(st);
    mark[st] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v : adj[u]) {
            if (mark[v] == 2) return v;
            if (!mark[v]) {
                mark[v] = 1;
                q.push(v);
            }
        }
    }
    assert(0);
}
int ask(int side, int u) {
    cout << char('A' + side) << " " << u << endl;
    int res; cin >> res;
    return res;
}
void solve() {
    for(auto u : imp[0]) mark[u] = 2;
    int need = BFS(ask(1, imp[1][0]));
    int needOth = ask(0, need);

    for(auto u : imp[1]) if (u == needOth) {
        cout << "C " << need << endl;
        return;
    }
    cout << "C -1" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n;
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 0; i <= 1; i++) {
            int n1;
            cin >> n1;
            imp[i] = {};
            while (n1--) {
                int u;
                cin >> u; imp[i].push_back(u);
            }
        }
        solve();
        reset();

    }
}