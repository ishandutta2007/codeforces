#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int start = 0;
        for (int i = 0; i < k; ++i) {
            int ptr = start;
            for (int j = 0; j < m; ++j) {
                int table_size = n / m + (j < n % m);
                cout << table_size << " ";
                while (table_size--) {
                    cout << ptr++ % n + 1 << " ";
                }
                cout << "\n";
            }
            start += (n % m) * (n / m + 1);
        }

        cout << "\n";
    }
}