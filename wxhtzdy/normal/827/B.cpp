#include <bits/stdc++.h>

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nodes;
    for (int i = 1; i < n - k; i++) {
        nodes.push_back(i);
    }
    std::vector<int> exits;
    for (int i = n - k; i < n; i++) {
        exits.push_back(i);
    }
    int root = 0;
    std::vector<std::vector<int>> path(k);
    for (int i = 0; i < nodes.size(); i++) {
        path[i % k].push_back(nodes[i]);
    }
    std::cout << path[0].size() + path[1].size() + 2 << "\n";
    for (int i = 0; i < k; i++) {
        if (path[i].size() == 0) {
            std::cout << root + 1 << " " << exits[i] + 1 << "\n";
            continue;
        }
        std::cout << root + 1 << " " << path[i][0] + 1 << "\n";
        for (int j = 1; j < path[i].size(); j++) {
            std::cout << path[i][j - 1] + 1 << " " << path[i][j] + 1 << "\n";
        }
        std::cout << path[i].back() + 1 << " " << exits[i] + 1 << "\n";
    }
    return 0;
}