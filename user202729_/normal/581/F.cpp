#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> vi;

int n;
std::vector<vi> adjlist;
vi parent, nleaf;

vi calc_dfs(int node) {
    if (adjlist[node].size() == 1 && node != 0) {
        nleaf[node] = 1;
        return vi {0, 1}; // 0 -> 0, 1 -> 1
    }
    vi result (1, 0); // 0 -> 0
    for (int c : adjlist[node]) {
        if (parent[node] != c) {
            parent[c] = node;
            vi tmp = calc_dfs(c);
            vi result1 (result.size() + tmp.size() - 1, 1000000000);
            for (int i = 0; i < result.size(); ++i) {
                for (int j = 0; j < tmp.size(); ++j) {
                    result1[i+j] = std::min(result1[i+j],
                        result[i] + tmp[j]);
                }
            }
            result = std::move(result1);

            nleaf[node] += nleaf[c]; // just sum
        }
    }
    /*
    std::cout << node << "-> ";
    for (int i : result) std::cout << i << " ";
    std::cout << "\n";
    */
    if (node != 0) {
        // reverse the result table, add to itself
        vi tmp = result;
        std::reverse(tmp.begin(), tmp.end());
        for (int i = 0; i < result.size(); ++i)
            result[i] = std::min(result[i], tmp[i]+1);
        /*
        std::cout << node << ":> ";
        for (int i : result) std::cout << i << " ";
        std::cout << "\n";
        */
    }
    return result;
}

int main() {
    std::cin >> n;
    adjlist.resize(n);
    for (int i = 1; i < n ; ++i) {
        int v1, v2;
        std::cin >> v1 >> v2;
        --v1; --v2;
        adjlist[v1].push_back(v2); adjlist[v2].push_back(v1);
    }
    parent.assign(n, -1);
    nleaf.assign(n, 0);
    vi result = calc_dfs(0);

    std::cout << result[
    (nleaf[0] + 1) / 2 // is the number of leaf of the tree div 2
    ];
}