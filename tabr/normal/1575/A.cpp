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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 1; j < m; j += 2) {
            s[i][j] = 'A' + 'Z' - s[i][j];
        }
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return s[i] < s[j];
    });
    for (int i : order) {
        cout << i + 1 << " ";
    }
    cout << '\n';
    return 0;
}