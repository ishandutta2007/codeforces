#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, int> elements;
    for (int k = 0; k < 2; ++k) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            elements[x] = max(elements[x], y);
        }
    }

    long long ans = 0;
    for (auto [x, y] : elements) {
        ans += y;
    }

    cout << ans << "\n";
}