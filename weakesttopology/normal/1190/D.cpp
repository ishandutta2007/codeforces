#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
constexpr int inf = std::numeric_limits<int>::max();
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::map<int, std::vector<int>> xs;
    for (int i = 0; i < N; ++i) {
        int x, y;
        std::cin >> x >> y;
        xs[-y].push_back(x);
    }
    ordered_set<int> on;
    int64_t ans = 0;
    for (auto& [y, V] : xs) {
        std::sort(V.begin(), V.end());
        V.push_back(inf);
        for (int i = 0; i + 1 < V.size(); ++i) {
            int x = V[i], nx = V[i + 1];
            on.insert(x);
            int ox = on.order_of_key(x), onx = on.order_of_key(nx);
            ans += 1LL * (ox + 1) * (onx - ox);
        }
    }
    std::cout << ans << '\n';
    exit(0);
}