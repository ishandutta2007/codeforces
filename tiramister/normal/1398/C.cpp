#include <iostream>
#include <map>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    lint ans = 0;

    int sum = 0;
    std::map<int, lint> cnt;
    cnt[0] = 1;

    while (n--) {
        char c;
        std::cin >> c;
        sum += c - '0';
        --sum;

        if (!cnt.count(sum)) cnt[sum] = 0;
        ans += cnt[sum];
        ++cnt[sum];
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}