#include <iostream>
#include <vector>
#include <string>

constexpr int N = 9;
std::vector<int> ps{0, 3, 6,
                    1, 4, 7,
                    2, 5, 8};

void solve() {
    std::vector<std::string> ss(N);
    for (auto& s : ss) std::cin >> s;

    for (int x = 0; x < N; ++x) {
        int y = ps[x];
        ss[x][y] = (ss[x][y] == '9' ? '1' : ss[x][y] + 1);
    }

    for (auto& s : ss) std::cout << s << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}