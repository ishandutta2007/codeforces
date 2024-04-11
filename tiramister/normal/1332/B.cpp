#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;
    return rev;
}

const std::vector<int>
    ps{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> ans(n);
    for (auto& a : ans) {
        int x;
        std::cin >> x;

        for (int i = 0; i < (int)ps.size(); ++i) {
            if (x % ps[i] == 0) {
                a = i;
                break;
            }
        }
    }

    auto xs = ans;
    auto revx = compress(xs);

    std::cout << xs.size() << std::endl;
    for (auto a : ans) std::cout << revx[a] + 1 << " ";
    std::cout << std::endl;
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