#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

std::vector<int> parent;
std::vector<std::vector<int>> adjlist;

double result(int node) {
    adjlist[node].erase(
        std::remove(adjlist[node].begin(), adjlist[node].end(), parent[node]),
        adjlist[node].end()
    );
    if (adjlist[node].empty()) {
        return 0;
    }
    double sumlen = 0;
    for (int child : adjlist[node]) {
        parent[child] = node;
        sumlen += result(child);
    }
    return sumlen / adjlist[node].size() + 1;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int ncity;
    std::cin >> ncity;
    adjlist.resize(ncity);
    parent.resize(ncity);
    for (int i = 1; i < ncity; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    parent[0] = -1;
    std::cout << std::fixed << std::setprecision(15) << result(0) << '\n';
}