#include <iostream>
#include <vector>

using lint = long long;
constexpr int L = 1000000;

int main() {
    lint n;
    std::cin >> n;

    std::vector<int> fronts, lasts;
    for (int i = 0; i < n; ++i) {
        int l;
        std::cin >> l;

        int front;
        std::cin >> front;
        --l;

        int prev = front;
        bool decreasing = true;
        while (l--) {
            int s;
            std::cin >> s;
            if (prev < s) {
                decreasing = false;
            }
            prev = s;
        }

        int last = prev;
        if (decreasing) {
            fronts.push_back(front);
            lasts.push_back(last);
        }
    }
    int m = fronts.size();

    std::vector<lint> acc(L + 1, 0);
    for (int i = 0; i < m; ++i) {
        ++acc[fronts[i]];
    }
    for (int i = 1; i <= L; ++i) {
        acc[i] += acc[i - 1];
    }

    lint ans = n * n;
    for (int i = 0; i < m; ++i) {
        ans -= acc[lasts[i]];
    }

    std::cout << ans << std::endl;
    return 0;
}