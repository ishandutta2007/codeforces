#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(nullptr);

    int n; cin >> n;

    int k = (2 * n + 1) / 3;

    cout << k << "\n";

    int odds = (k + 1) / 4;
    for (int i = 0; i < odds; ++i) {
        int a = odds - i, b = odds - i + (2 * i + 1);
        cout << a << " " << b << "\n";
        cout << b << " " << a << "\n";
    }

    int evens = (k + 1) / 2 - odds;
    for (int i = 0; i < evens; ++i) {
        int a = odds * 2 + evens - i, b = odds * 2 + evens - i + (2 * i);
        if (i) cout << a << " " << b << "\n";
        cout << b << " " << a << "\n";
    }

    if (k % 2 == 0) cout << k << " " << k << "\n";
}