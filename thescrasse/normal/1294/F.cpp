// 1294F
// tre nodi che massimizzano gli archi su almeno un simple path

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, s, dist[200010][2], st, nd, parent[200010], l, r, ls;
bool visited[200010];
vector<long long> adj[200010];
queue<long long> q;
vector<long long> ms;

void bfs(vector<long long> st, int j2) {
    j = j2;
    for (i = 1; i <= n; i++) {
        dist[i][j] = -1;
        visited[i] = false;
    }
    for (auto u : st) {
        dist[u][j] = 0;
        q.push(u);
        visited[u] = true;
    }

    while (!q.empty()) {
        s = q.front();
        // cout << s << endl;
        q.pop();
        for (auto u : adj[s]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
                if (j == 0) {
                    parent[u] = s;
                }
                dist[u][j] = dist[s][j] + 1;
            }
        }
    }
    // cout << endl;
}

long long checkm() {
    long long m = -2;
    long long r = -1;
    for (i = 1; i <= n; i++) {
        if (dist[i][j] > m) {
            m = dist[i][j];
            r = i;
        }
    }
    // cout << m << endl;
    if (j == 1) {
        res += m;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    res = 0;
    cin >> n;
    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs({1}, 0);
    st = checkm();

    // cout << st << endl;
    bfs({st}, 1);
    nd = checkm();

    l = st;
    r = nd;
    ms.push_back(st);
    ms.push_back(nd);
    if (dist[l][0] < dist[r][0]) {
        swap(l, r);
    }
    while (dist[l][0] != dist[r][0]) {
        l = parent[l];
        ms.push_back(l);
    }
    while (l != r) {
        l = parent[l];
        r = parent[r];
        ms.push_back(l);
        if (l != r) {
            ms.push_back(r);
        }
    }

    bfs(ms, 1);
    ls = checkm();
    if (ls == st || ls == nd) {
        if (st != 1 && nd != 1) {
            ls = 1;
        } else if (st != 2 && nd != 2) {
            ls = 2;
        } else {
            ls = 3;
        }
    }
    cout << res << endl;
    cout << st << ' ' << nd << ' ' << ls;

    return 0;
}