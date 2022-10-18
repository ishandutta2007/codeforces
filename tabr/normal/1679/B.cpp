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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    vector<pair<int, int>> b(n + 1);
    for (int i = 0; i < n; i++) {
        b[i] = make_pair(a[i], -1);
    }
    b[n] = make_pair(-1, -1);
    for (int t = 0; t < q; t++) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            if (b[i].second < b[n].second) {
                b[i] = b[n];
            }
            sum -= b[i].first;
            sum += x;
            b[i] = make_pair(x, t);
        } else {
            int x;
            cin >> x;
            b[n] = make_pair(x, t);
            sum = 1LL * x * n;
        }
        cout << sum << '\n';
    }
    return 0;
}