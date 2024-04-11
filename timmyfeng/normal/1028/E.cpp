#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> b(n);
    for (auto &i : b) {
        cin >> i;
    }

    int k = -1;
    for (int i = 0; i < n; ++i) {
        if (b[i] > b[(i + n - 1) % n]) {
            k = i;
        }
    }

    if (k == -1) {
        if (b[0] == 0) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << 1 << " ";
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
        exit(0);
    }

    vector<long long> a(n);
    a[k] = (long long) b[k] * INT_MAX;

    for (int i = (k + n - 1) % n; i != k; i = (i + n - 1) % n) {
        a[i] = a[(i + 1) % n] + b[i];
    }
    a[k] = b[k];

    cout << "YES\n";
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";

    for (int i = 0; i < n; ++i) {
        assert(a[i] % a[(i + 1) % n] == b[i]);
    }
}