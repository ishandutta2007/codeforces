#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    cout << (6 * n - 1) * k << "\n";
    for (int i = 0; i < n; ++i) {
        for (auto j : {1, 2, 3, 5}) {
            cout << (6 * i + j) * k << " ";
        }
        cout << "\n";
    }
}