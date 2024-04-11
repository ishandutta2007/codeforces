#include <iostream>
#include <vector>
#include <string>
#include <functional>

const std::vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> ss(n);
    for (auto& s : ss) std::cin >> s;

    bool emptyrow = false;
    for (int x = 0; x < n; ++x) {
        int l = 0;
        while (l < m && ss[x][l] == '.') ++l;

        if (l == m) {
            emptyrow = true;
            continue;
        }

        int r = m - 1;
        while (r >= 0 && ss[x][r] == '.') --r;

        bool judge = true;
        for (int y = l; y <= r; ++y) {
            if (ss[x][y] == '.') judge = false;
        }

        if (!judge) {
            std::cout << "-1\n";
            return;
        }
    }

    bool emptycol = false;
    for (int y = 0; y < m; ++y) {
        int l = 0;
        while (l < n && ss[l][y] == '.') ++l;

        if (l == n) {
            emptycol = true;
            continue;
        }

        int r = n - 1;
        while (r >= 0 && ss[r][y] == '.') --r;

        bool judge = true;
        for (int x = l; x <= r; ++x) {
            if (ss[x][y] == '.') judge = false;
        }

        if (!judge) {
            std::cout << "-1\n";
            return;
        }
    }

    if (emptyrow != emptycol) {
        std::cout << "-1\n";
        return;
    }

    std::function<void(int, int)> dfs =
        [&](int x, int y) -> void {
        ss[x][y] = '.';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i],
                ny = y + dy[i];
            if (nx < 0 || n <= nx ||
                ny < 0 || m <= ny ||
                ss[nx][ny] == '.') continue;
            dfs(nx, ny);
        }
    };

    int ans = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (ss[x][y] == '#') {
                dfs(x, y);
                ++ans;
            }
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