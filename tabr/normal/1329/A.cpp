#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    vector<int> l(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i];
        if (i + l[i] > n) {
            cout << -1 << '\n';
            return 0;
        }
    }
    vector<int> p(m);
    iota(p.begin(), p.end(), 1);
    int lst = n;
    for (int i = m - 1; i >= 0; i--) {
        if (p[i] + l[i] - 1 < lst) {
            p[i] = lst + 1 - l[i];
            lst = p[i] - 1;
        } else {
            break;
        }
        if (i == 0) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << p[i] << " ";
    }
    cout << '\n';
    return 0;
}