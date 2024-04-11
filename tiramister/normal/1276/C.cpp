#include <iostream>
#include <vector>
#include <map>
#include <cassert>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n;
    std::cin >> n;

    std::map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (!cnt.count(x)) cnt[x] = 0;
        ++cnt[x];
    }

    std::vector<std::vector<int>> ctox(n + 1);
    for (auto p : cnt) {
        ctox[p.second].push_back(p.first);
    }

    int hmax = -1;
    {
        int smax = -1;
        int inc = cnt.size(), sum = 0;

        for (int h = 1; h <= n; ++h) {
            sum += inc;
            inc -= ctox[h].size();

            if (sum / h >= h && sum / h * h > smax) {
                hmax = h;
                smax = sum / h * h;
            }
        }
    }

    std::vector<int> xs;
    for (int h = 1; h <= n; ++h) {
        for (auto x : ctox[h]) {
            int c = std::min(h, hmax);
            while (c--) {
                xs.push_back(x);
            }
        }
    }
    int wmax = xs.size() / hmax;

    std::cout << hmax * wmax << "\n"
              << hmax << " " << wmax << "\n";

    auto ans = vec(hmax, vec(wmax, -1));
    for (int w = 0; w < wmax; ++w) {
        for (int h = 0; h < hmax; ++h) {
            ans[h][(h + w) % wmax] = xs.back();
            xs.pop_back();
        }
    }

    for (const auto& v : ans) {
        for (const auto& x : v) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}