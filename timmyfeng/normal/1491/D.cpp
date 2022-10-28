#include <bits/stdc++.h>
using namespace std;

const int L = 30;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        int u, v;
        cin >> u >> v;

        bool delta = true;
        while (u < v && delta) {
            delta = false;
            for (int i = L - 1; i >= 0; --i) {
                if ((u & (1 << i)) > 0 && u + (1 << i) <= v) {
                    u += 1 << i;
                    delta = true;
                    break;
                }
            }
        }

        cout << (u == v ? "YES" : "NO") << "\n";
    }
}