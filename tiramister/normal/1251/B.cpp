#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using lint = long long;
using ldouble = long double;

int main() {
    int q;
    std::cin >> q;
    while (q--) {
        int n;
        std::cin >> n;

        std::vector<int> req(n);
        std::vector<int> cnt(2, 0);

        for (auto& r : req) {
            std::string s;
            std::cin >> s;

            r = s.length() / 2;
            for (int j = 0; j <= 1; ++j) {
                char c = '0' + j;
                cnt[j] += std::count(s.begin(), s.end(), c);
            }
        }

        int sum = cnt[0] / 2 + cnt[1] / 2;

        std::sort(req.begin(), req.end());
        int ans = 0;
        for (int r : req) {
            if (sum >= r) {
                ++ans;
                sum -= r;
            } else {
                break;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}