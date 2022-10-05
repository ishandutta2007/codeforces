//
// Created by Danny Mittal on 6/4/20.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

struct part {
    int a;
    int b;
};

struct edge {
    int other;
    int ix1;
    int ix2;

    edge(int a, int b, int c): other(a), ix1(b), ix2(c) {}
};

part parts[500000];
vector<vector<edge>> adj;
bool used[500000];
vector<int> answer;

void recur(int a, edge prev) {
    while (!adj[a].empty()) {
        edge ej = adj[a].back();
        adj[a].pop_back();
        if (!used[(ej.ix1 - 1) / 2]) {
            used[(ej.ix1 - 1) / 2] = true;
            recur(ej.other, ej);
        }
    }
    if (prev.other != -1) {
        answer.push_back(prev.ix2);
        answer.push_back(prev.ix1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
        cin >> parts[j].a >> parts[j].b;
    }
    for (int e = 20; e >= 0; e--) {
        int all = (1 << e) - 1;
        adj.clear();
        for (int a = 0; a < (1 << e); a++) {
            adj.emplace_back();
        }
        for (int j = 0; j < n; j++) {
            int a = parts[j].a & all;
            int b = parts[j].b & all;
            adj[a].push_back(edge(b, (2 * j) + 1, (2 * j) + 2));
            adj[b].push_back(edge(a, (2 * j) + 2, (2 * j) + 1));
        }
        bool allEven = true;
        for (int a = 0; a < (1 << e); a++) {
            if (adj[a].size() % 2 == 1) {
                allEven = false;
                break;
            }
        }
        if (allEven) {
            bool seen[1 << 20];
            memset(seen, false, (1 << e) * sizeof(bool));
            stack<int> dfs;
            int r = 0;
            while (adj[r].empty()) {
                r++;
            }
            seen[r] = true;
            dfs.push(r);
            while (!dfs.empty()) {
                int a = dfs.top();
                dfs.pop();
                for (edge ej: adj[a]) {
                    int b = ej.other;
                    if (!seen[b]) {
                        seen[b] = true;
                        dfs.push(b);
                    }
                }
            }
            bool connected = true;
            for (int a = 0; a < (1 << e); a++) {
                if (!adj[a].empty() && !seen[a]) {
                    connected = false;
                    break;
                }
            }
            if (connected) {
                memset(used, false, n * sizeof(bool));
                recur(r, edge(-1, -1, -1));
                cout << e << endl;
                for (int j = 0; j < 2 * n; j++) {
                    cout << answer[j] << ' ';
                }
                cout << endl;
                return 0;
            }
        }
    }
}