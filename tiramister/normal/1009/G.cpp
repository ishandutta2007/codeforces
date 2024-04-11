#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

constexpr int N = 1 << 6;

void solve() {
    int n;
    std::vector<int> cnt(6, 0);
    {
        std::string s;
        std::cin >> s;

        n = s.length();
        for (char c : s) ++cnt[c - 'a'];
    }

    std::vector<int> allow(n, N - 1);
    {
        int q;
        std::cin >> q;

        while (q--) {
            int i;
            std::string s;
            std::cin >> i >> s;
            --i;

            allow[i] = 0;
            for (char c : s) {
                allow[i] |= (1 << (c - 'a'));
            }
        }
    }

    std::vector<int> req(N, 0);
    for (auto b : allow) {
        for (int nb = 0; nb < N; ++nb) {
            if ((nb & b) == b) ++req[nb];
        }
    }

    auto check = [&]() {
        for (int b = 0; b < N; ++b) {
            int sup = 0;
            for (int i = 0; i < 6; ++i) {
                if ((b >> i) & 1) sup += cnt[i];
            }
            if (sup < req[b]) return false;
        }
        return true;
    };

    std::string ans(n, '$');
    for (int i = 0; i < n; ++i) {
        int b = allow[i];
        for (int nb = 0; nb < N; ++nb) {
            if ((nb & b) == b) --req[nb];
        }

        for (int c = 0; c < 6; ++c) {
            if (!((b >> c) & 1)) continue;

            --cnt[c];
            if (check()) {
                ans[i] = c + 'a';
                break;
            }
            ++cnt[c];
        }

        if (ans[i] == '$') {
            std::cout << "Impossible\n";
            return;
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