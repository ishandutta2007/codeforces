#include <iostream>
#include <string>

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::string ans;
    for (int i = 0; i < a; ++i) {
        ans.push_back('a' + std::min(i, b - 1));
    }
    for (int i = a; i < n; ++i) {
        ans.push_back(ans[i - a]);
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}