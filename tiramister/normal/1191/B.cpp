#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool judge(std::vector<std::string> ss) {
    int n = ss.size();
    std::sort(ss.begin(), ss.end());

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < j; ++k) {
                auto p = ss[i], q = ss[j], r = ss[k];

                if (p[1] != q[1] || q[1] != r[1]) continue;
                if (p[0] == q[0] && q[0] == r[0]) return true;
                if (p[0] - q[0] == 1 &&
                    q[0] - r[0] == 1) return true;
            }
        }
    }

    return false;
}

int main() {
    std::vector<std::string> ss(3);
    for (auto& s : ss) std::cin >> s;

    if (judge(ss)) {
        std::cout << 0 << std::endl;
        return 0;
    }

    for (char n = '1'; n <= '9'; ++n) {
        for (char s : std::string("smp")) {
            std::string p = std::string{n, s};
            ss.push_back(p);

            if (judge(ss)) {
                std::cout << 1 << std::endl;
                return 0;
            }

            ss.pop_back();
        }
    }

    std::cout << 2 << std::endl;
    return 0;
}