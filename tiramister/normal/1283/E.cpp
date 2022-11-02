#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

const std::vector<int> dx{-1, 0, 1};
constexpr int INF = 1 << 30;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;
    std::sort(xs.begin(), xs.end());

    auto mindp = vec(3, 1), maxdp = vec(3, 1);
    for (int i = 1; i < n; ++i) {
        auto nmindp = vec(3, INF), nmaxdp = vec(3, 0);

        for (int j = 0; j < 3; ++j) {
            int px = xs[i - 1] + dx[j];
            for (int k = 0; k < 3; ++k) {
                int nx = xs[i] + dx[k];
                if (nx < px) continue;

                int cost = (px != nx);
                nmindp[k] = std::min(nmindp[k], mindp[j] + cost);
                nmaxdp[k] = std::max(nmaxdp[k], maxdp[j] + cost);
            }
        }

        std::swap(mindp, nmindp);
        std::swap(maxdp, nmaxdp);
    }

    std::cout << *std::min_element(mindp.begin(), mindp.end()) << " "
              << *std::max_element(maxdp.begin(), maxdp.end()) << std::endl;
    return 0;
}