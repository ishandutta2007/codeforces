#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;

array<int, 2> cycle[N];
int par[N], in[N], t;
vector<int> adj[N];

vector<int> path(int a, int b) {
    vector<int> ans;
    while (b != a) {
        ans.push_back(b);
        b = par[b];
    }
    ans.push_back(a);
    return ans;
}

void print(vector<int> p) {
    cout << p.size() << " ";
    for (auto i : p) {
        cout << i << " ";
    }
    cout << "\n";
}

void process(array<int, 2> a, array<int, 2> b) {
    int u = a[1], v = b[1];
    while (u != v) {
        if (in[u] < in[v]) {
            swap(u, v);
        }
        u = par[u];
    }

    u = in[a[0]] > in[b[0]] ? a[0] : b[0];

    cout << "YES\n";

    print(path(u, v));

    for (auto [x, y] : {a, b}) {
        vector<int> p = path(x, y);
        reverse(p.begin(), p.end());
        rotate(p.begin(), find(p.begin(), p.end(), v), p.end());
        p.erase(find(p.begin(), p.end(), u) + 1, p.end());
        print(p);
    }

    exit(0);
}

void dfs(int u) {
    in[u] = ++t;
    for (auto c : adj[u]) {
        if (c != par[u]) {
            if (in[c] == 0) {
                par[c] = u;
                dfs(c);
            } else if (in[c] < in[u]) {
                for (int v = u; v != c; v = par[v]) {
                    if (cycle[v][0] == 0) {
                        cycle[v] = {c, u};
                    } else {
                        process({c, u}, cycle[v]);
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            dfs(i);
        }
    }

    cout << "NO\n";
}