#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

std::vector<std::pair<char, int>> runlength(const std::string& s) {
    std::vector<std::pair<char, int>> res;
    for (char c : s) {
        if (res.empty() || c != res.back().first) {
            res.emplace_back(c, 1);
        } else {
            ++res.back().second;
        }
    }
    return res;
}

void solve() {
    int n, a, b;
    std::string s;
    std::cin >> n >> a >> b >> s;

    auto ps = runlength(s);
    int ans = 0, rem = 0;

    for (auto [c, m] : ps) {
        if (c == '*') continue;

        {
            int ok = std::min(a, m / 2);
            a -= ok;
            ans += ok;
        }

        {
            int ok = std::min(b, m / 2);
            b -= ok;
            ans += ok;
        }

        rem += m % 2;
    }

    {
        int ok = std::min(a, rem);
        ans += ok;
        rem -= ok;
    }

    {
        int ok = std::min(b, rem);
        ans += ok;
        rem -= ok;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}