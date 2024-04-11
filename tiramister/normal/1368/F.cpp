#include <iostream>
#include <vector>
#include <set>

int n;
std::set<int> s;

void query(const std::vector<int>& xs) {
    int k = xs.size();
    std::cout << k;
    for (auto x : xs) {
        s.insert(x);
        std::cout << " " << x + 1;
    }
    std::cout << std::endl;

    if (k == 0) std::exit(0);

    int x;
    std::cin >> x;
    if (x == -1) std::exit(1);

    --x;
    for (int i = 0; i < k; ++i) s.erase((x + i) % n);
}

void solve() {
    std::cin >> n;

    int k = 0, max = 0;
    for (int kk = 1; kk <= n; ++kk) {
        int x = n - (n + kk - 1) / kk - (kk - 1);
        if (x > max) {
            k = kk;
            max = x;
        }
    }

    while ((int)s.size() < max) {
        std::vector<int> xs;
        for (int x = 0; x < n && (int)xs.size() < k; ++x) {
            if (x % k != 0 && !s.count(x)) xs.push_back(x);
        }
        query(xs);
    }

    query(std::vector<int>());
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}