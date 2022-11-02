#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using lint = long long;

int main() {
    int n;
    std::cin >> n;

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;
    std::sort(xs.begin(), xs.end());

    std::function<lint(int, int, int)>
        dfs = [&](int l, int r, int k) {
            if (k < 0) return 0LL;

            int ok = r, ng = l - 1;
            // x in [ok, r) <=> x's k-th bit is 1
            while (ok - ng > 1) {
                int mid = (ok + ng) / 2;
                (((xs[mid] >> k) & 1) ? ok : ng) = mid;
            }

            if (ok == l || ok == r) {
                return dfs(l, r, k - 1);
            } else {
                lint ret = std::min(dfs(l, ok, k - 1), dfs(ok, r, k - 1));
                return ret | (1LL << k);
            }
        };

    std::cout << dfs(0, n, 40) << std::endl;
    return 0;
}