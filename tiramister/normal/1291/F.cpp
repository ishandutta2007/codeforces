#include <iostream>
#include <vector>
#include <numeric>

bool query(int i) {
    ++i;
    if (i <= 0) {
        std::cout << 'R' << std::endl;
        return false;
    }

    std::cout << "? " << i << std::endl;
    char c;
    std::cin >> c;
    return c == 'Y';
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    int bsize = (k == 1 ? 1 : k / 2);
    int m = n / bsize;

    std::vector<bool> ans(n, true);
    for (int s = 0; s < m / 2; ++s) {
        int v = s;

        std::vector<bool> visited(m, false);
        int d = 1, sign = 1;

        while (true) {
            visited[v] = true;

            int base = v * bsize;
            for (int i = 0; i < bsize; ++i) {
                int u = base + i;
                if (!ans[u] || query(u)) ans[u] = false;
            }

            v = (v + d * sign + m) % m;
            ++d, sign = -sign;
            if (visited[v]) break;
        }
        query(-1);
    }

    std::cout << "! " << std::accumulate(ans.begin(), ans.end(), 0)
              << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}