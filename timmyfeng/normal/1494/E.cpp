#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<array<int, 2>, int> letter;
    int odd = 0, even = 0;

    while (m--) {
        char type;
        cin >> type;

        if (type == '+') {
            int u, v;
            char c;
            cin >> u >> v >> c;

            letter[{u, v}] = c;
            if (letter.count({v, u}) == 1) {
                odd += letter[{v, u}] == c;
                ++even;
            }
        } else if (type == '-') {
            int u, v;
            cin >> u >> v;

            if (letter.count({v, u}) == 1) {
                odd -= letter[{v, u}] == letter[{u, v}];
                --even;
            }
            letter.erase({u, v});
        } else {
            int k;
            cin >> k;

            cout << ((k % 2 == 0 ? odd : even) > 0 ? "YES" : "NO") << "\n";
        }
    }
}