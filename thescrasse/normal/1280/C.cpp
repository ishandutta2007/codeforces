// 1280C
// minima e massima somma delle distanze minime tra coppie disgiunte in un tree
// idee: per ogni arco calcolo quante volte viene preso nelle soluzioni ottimali
// controllo il numero di elementi nei subtree

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, check1, a, b, c, v[200010];
bool visited[200010];
vector<long long> adj[200010];
vector<array<long long, 3>> el;

void dfs(int s) {
    v[s] = 1;
    visited[s] = true;
    for (auto u : adj[s]) {
        if (visited[u]) {
            continue;
        }
        dfs(u);
        v[s] += v[u];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    for (i1 = 0; i1 < t; i1++) {
        cin >> k;
        k *= 2;
        for (i = 1; i <= k; i++) {
            adj[i].clear();
            el.clear();
        }
        for (i = 0; i < k - 1; i++) {
            cin >> a >> b >> c;
            adj[a].push_back(b);
            adj[b].push_back(a);
            el.push_back({a, b, c});
        }

        for (i = 1; i <= k; i++) {
            v[i] = 0;
            visited[i] = false;
        }

        dfs(1);

        res = 0;
        for (auto u : el) {
            a = min(v[u[0]], v[u[1]]);
            res = res + u[2] * (a % 2);
        }
        cout << res << ' ';

        res = 0;
        for (auto u : el) {
            a = min(v[u[0]], v[u[1]]);
            a = min(a, k - a);
            res = res + u[2] * a;
        }
        cout << res << endl;
    }

    return 0;
}