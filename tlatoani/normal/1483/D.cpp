//
// Created by Danny Mittal on 3/21/21.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<pair<int, int>> adj[601];
int dist[601][601];
int special[601][601];

const int BILLION = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            dist[a][b] = BILLION;
            special[a][b] = BILLION;
        }
        dist[a][a] = 0;
    }
    for (; m; m--) {
        int a, b, l;
        cin >> a >> b >> l;
        dist[a][b] = l;
        dist[b][a] = l;
        adj[a].emplace_back(b, l);
        adj[b].emplace_back(a, l);
    }
    for (int c = 1; c <= n; c++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                dist[a][b] = min(dist[a][b], dist[a][c] + dist[c][b]);
            }
        }
    }
    int q;
    for (cin >> q; q; q--) {
        int a, b, l;
        cin >> a >> b >> l;
        special[a][b] = BILLION - l;
        special[b][a] = BILLION - l;
    }
    for (int c = 1; c <= n; c++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                special[a][b] = min(special[a][b], special[c][b] + dist[c][a]);
            }
        }
    }
    for (int c = 1; c <= n; c++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                special[a][b] = min(special[a][b], special[a][c] + dist[c][b]);
            }
        }
    }
    int answer = 0;
    for (int a = 1; a <= n; a++) {
        for (pair<int, int> edge : adj[a]) {
            int b = edge.first;
            int l = edge.second;
            if (a < b && special[a][b] + l <= BILLION) {
                answer++;
            }
        }
    }
    cout << answer << endl;
}