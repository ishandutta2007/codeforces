#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void solve() {
    int a, b;
    std::string s;
    std::cin >> a >> b >> s;
    s.push_back('X');

    std::vector<int> segs;
    int cnt = 0;
    for (char c : s) {
        if (c == 'X') {
            if (cnt >= b) segs.push_back(cnt);
            cnt = 0;
        } else {
            ++cnt;
        }
    }
    std::sort(segs.begin(), segs.end());
    int n = segs.size();

    int over2b = 0;
    for (auto x : segs) {
        if (x < a) {
            std::cout << "NO" << std::endl;
            return;
        }
        if (x >= b * 2) ++over2b;
    }

    if (over2b == 0) {
        std::cout << (n % 2 == 1 ? "YES" : "NO") << std::endl;
        return;
    }
    if (over2b >= 2) {
        std::cout << "NO" << std::endl;
        return;
    }

    int x = segs.back();
    --n;

    std::vector<int> rem(2);
    for (rem[0] = 0; rem[0] + a <= x; ++rem[0]) {
        rem[1] = x - a - rem[0];
        int m = n;
        bool ok = true;
        for (auto r : rem) {
            if (r < b) {
                continue;
            } else if (a <= r && r < b * 2) {
                ++m;
            } else {
                ok = false;
            }
        }

        if (ok && m % 2 == 0) {
            std::cout << "YES" << std::endl;
            return;
        }
    }
    std::cout << "NO" << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}