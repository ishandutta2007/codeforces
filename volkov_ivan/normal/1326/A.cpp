#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << -1 << "\n";
            continue;
        }
        cout << 2;
        for (int j = 0; j < n - 1; j++) cout << 3;
        cout << "\n";
    }
    return 0;
}