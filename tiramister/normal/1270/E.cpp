#include <iostream>
#include <vector>
#include <cassert>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> xs[i] >> ys[i];
    }

    while (true) {
        bool odd = false, even = false;
        for (int i = 0; i < n; ++i) {
            if ((xs[i] + ys[i]) % 2 == 0) {
                even = true;
            } else {
                odd = true;
            }
        }

        if (odd && even) {
            std::vector<int> ans;
            for (int i = 0; i < n; ++i) {
                if ((xs[i] + ys[i]) % 2 == 0) {
                    ans.push_back(i + 1);
                }
            }
            std::cout << ans.size() << std::endl;
            for (auto i : ans) std::cout << i << " ";
            std::cout << std::endl;
            break;
        }

        if (odd) {
            for (int i = 0; i < n; ++i) ++xs[i];
        }

        odd = false, even = false;
        for (int i = 0; i < n; ++i) {
            assert((xs[i] + ys[i]) % 2 == 0);
            if (xs[i] % 2 == 0) {
                even = true;
            } else {
                odd = true;
            }
        }

        if (odd && even) {
            std::vector<int> ans;
            for (int i = 0; i < n; ++i) {
                if (xs[i] % 2 == 0) {
                    ans.push_back(i + 1);
                }
            }
            std::cout << ans.size() << std::endl;
            for (auto i : ans) std::cout << i << " ";
            std::cout << std::endl;
            break;
        }

        if (odd) {
            for (int i = 0; i < n; ++i) {
                ++xs[i];
                ++ys[i];
            }
        }

        for (int i = 0; i < n; ++i) {
            assert(xs[i] % 2 == 0 && ys[i] % 2 == 0);
            xs[i] /= 2;
            ys[i] /= 2;
        }
    }
    return 0;
}