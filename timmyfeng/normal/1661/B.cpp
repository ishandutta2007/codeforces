#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto get_count = [&](int x) {
        int count = 0;
        while (x % 32768) x *= 2, ++count;
        return count;
    };

    int n; cin >> n;

    while (n--) {
        int x; cin >> x;

        int ans = 15;
        for (int i = 0; i <= ans; ++i) ans = min(ans, get_count(x + i) + i);

        cout << ans << " ";
    }
    cout << "\n";
}