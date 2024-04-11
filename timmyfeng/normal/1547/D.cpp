#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int z = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cout << (z & ~x) << " ";
            z |= x;
        }

        cout << "\n";
    }
}