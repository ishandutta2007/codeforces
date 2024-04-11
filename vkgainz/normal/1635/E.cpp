#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
#include <array>
#include <numeric>
#include <unordered_set>
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<bool, int>>> adj(n);
    vector<int> dir(n);
    vector<vector<int>> le(n);
    for (int i = 0; i < m; i++) {
        int type, x, y;
        cin >> type >> x >> y;
        --x, --y;
        if (type == 1) {
            adj[x].push_back({1, y});
            adj[y].push_back({1, x});
        } else {
            adj[x].push_back({0, y});
            adj[y].push_back({0, x});
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (dir[i] != 0) continue;
        dir[i] = 1;
        q.push(i);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (auto next : adj[curr]) {
                if (dir[next.second] == 0) {
                    dir[next.second] = 3 - dir[curr];
                    if (next.first) {
                        if (dir[next.second] == 2) {
                            le[curr].push_back(next.second);
                        } else {
                            le[next.second].push_back(curr);
                        }
                    } else {
                        if (dir[next.second] == 2) {
                            le[next.second].push_back(curr);
                        } else {
                            le[curr].push_back(next.second);
                        }
                    }
                    q.push(next.second);
                } else if (dir[next.second] == dir[curr]) {
                    cout << "NO" << "\n";
                    return 0;
                } else {
                    if (next.first) {
                        if (dir[next.second] == 2) {
                            le[curr].push_back(next.second);
                        } else {
                            le[next.second].push_back(curr);
                        }
                    } else {
                        if (dir[next.second] == 2) {
                            le[next.second].push_back(curr);
                        } else {
                            le[curr].push_back(next.second);
                        }
                    }
                }
            }
        }
    }
    //top sort
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        for (int j : le[i]) {
            ++deg[j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0)
            q.push(i);
    }
    int x = 0;
    vector<int> ans(n);
    while (!q.empty()) {
        auto curr = q.front();
        ans[curr] = x++;
        q.pop();
        for (int next : le[curr]) {
            --deg[next];
            if (deg[next] == 0) q.push(next);
        }
    }
    if (x != n) cout << "NO" << "\n";
    else {
        cout << "YES" << "\n";
        for (int i = 0; i < n; i++) {
            if (dir[i] == 1) cout << "L" << " ";
            else cout << "R" << " ";
            cout << ans[i] << "\n";
        }
    }
}