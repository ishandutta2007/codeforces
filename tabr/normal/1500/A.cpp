#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> b(5000001, {-1, -1});
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto p = b[a[i] + a[j]];
            if (p.first != -1 && p.first != i && p.second != i && p.second != j && p.first != j) {
                cout << "YES" << '\n';
                cout << p.first + 1 << " " << p.second + 1 << " " << i + 1 << " " << j + 1 << '\n';
                return 0;
            } else {
                b[a[i] + a[j]] = {i, j};
            }
        }
    }
    cout << "NO" << '\n';
    return 0;
}