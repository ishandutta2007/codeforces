#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        vector<int> l(3);
        for (auto &i : l) cin >> i;

        ranges::sort(l);

        cout << (l[0] + l[1] == l[2] || l[0] == l[1] && l[2] % 2 == 0 || l[0] % 2 == 0 && l[1] == l[2] ? "YES" : "NO") << "\n";
    }
}