#include <iostream>
#include <string>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int ans = 0;
    int i = 0;

    while (i < n) {
        ++ans;
        if (s.substr(i, 2) == "UR" ||
            s.substr(i, 2) == "RU") {
            i += 2;
        } else {
            ++i;
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}