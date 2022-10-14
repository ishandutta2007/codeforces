#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> l(m), r(m), d(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> d[i];
        l[i]--; r[i]--;
    }
    vector<long long> w(m + 1, 0);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        w[x]++; w[y + 1]--;
    }
    long long bal = 0;
    vector<long long> t(m, 0);
    for (int i = 0; i < m; i++) {
        bal += w[i];
        t[i] = bal;
    }
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < m; i++) {
        h[l[i]] += (long long) t[i] * d[i];
        h[r[i] + 1] -= (long long) t[i] * d[i];
    }
    bal = 0;
    for (int i = 0; i < n; i++) {
        bal += h[i];
        a[i] += bal;
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << a[i];
    }
    return 0;
}