#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n, q;
    std::cin >> n >> q;

    auto state = vec(2, vec(n, 0));
    int cnt = 0;
    while (q--) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;

        int sign = (state[x][y] ? -1 : 1);
        int nx = 1 - x;
        for (int dy = -1; dy <= 1; ++dy) {
            int ny = y + dy;
            if (ny < 0 || n <= ny) continue;
            cnt += sign * state[nx][ny];
        }

        state[x][y] = 1 - state[x][y];

        std::cout << (cnt ? "No" : "Yes") << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}