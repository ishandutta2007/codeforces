// 1205B
// due interi sono collegati se l'and  > 0, trovare ciclo pi corto

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, check2, a[100010], b, dist[100010], f, ec, nc;
bool visited[100010];
vector<long long> adj[100010];
queue<long long> q;
vector<pair<long long, long long>> el;

long long bfs(int s, int f) {
    //cout << s << ' ' << f << endl;
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    q.push(s);
    dist[s] = 0;
    visited[s] = true;
    while (!q.empty()) {
        b = q.front();
        q.pop();
        for (auto u : adj[b]) {
            if ((b == s && u == f) || (b == f && u == s)) {
                continue;
            }
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
                dist[u] = dist[b] + 1;
            }
        }
    }
    if (!visited[f]) {
        return 69420;
    } else {
        return dist[f] + 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    nc = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i + 1];
        if (a[i + 1] != 0) {
            nc++;
        }
    }

    if (nc > 120) {
        cout << 3;
        return 0;
    }

    ec = 0;

    for (i = 1; i < n; i++) {
        if (a[i] == 0) {
            continue;
        }
        for (j = i + 1; j <= n; j++) {
            if (a[j] == 0) {
                continue;
            }
            if ((a[i] & a[j]) != 0) {
                adj[i].push_back(j);
                adj[j].push_back(i);
                el.push_back({i, j});
                ec++;
                if (ec > 60) {
                    cout << 3;
                    return 0;
                }
            }
        }
    }

    res = 69420;

    for (auto u : el) {
        i = u.first;
        j = u.second;
        res = min(res, bfs(i, j));
    }

    if (res == 69420) {
        cout << -1;
    } else {
        cout << res;
    }

    return 0;
}