#include <iostream>

void solve() {
    int n;
    std::cin >> n;

    int pa, pb;
    std::cin >> pa >> pb;
    --n;

    bool ans = (pa >= pb);
    while (n--) {
        int a, b;
        std::cin >> a >> b;

        int da = a - pa,
            db = b - pb;
        if (da < 0 || db < 0 ||
            da < db || a < b) ans = false;

        pa = a;
        pb = b;
    }

    std::cout << (ans ? "YES" : "NO") << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}