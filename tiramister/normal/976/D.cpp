#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> ds(n);
    for (auto& d : ds) std::cin >> d;

    std::vector<std::pair<int, int>> ans;
    while (!ds.empty()) {
        int vnum = ds.back() + 1;

        if (ds.size() == 1) {
            for (int v = 0; v < vnum; ++v) {
                for (int u = 0; u < v; ++u) {
                    ans.emplace_back(u, v);
                }
            }
            break;
        }

        int k = ds.front();
        for (int v = vnum - k; v < vnum; ++v) {
            for (int u = 0; u < v; ++u) {
                ans.emplace_back(u, v);
            }
        }

        for (auto& d : ds) d -= k;
        ds.erase(ds.begin());
        ds.pop_back();
    }

    std::cout << ans.size() << std::endl;
    for (auto p : ans) {
        std::cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}