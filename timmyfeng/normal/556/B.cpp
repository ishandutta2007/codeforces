#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    int x = a[0];

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            a[i] = (a[i] - x + n) % n;
        } else {
            a[i] = (a[i] + x) % n;
        }

        if (a[i] != i) {
            cout << "No\n";
            exit(0);
        }
    }

    cout << "Yes\n";
}