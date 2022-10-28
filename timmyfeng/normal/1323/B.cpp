#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (auto& i : a) {
        cin >> i;
    }
    for (auto& i : b) {
        cin >> i;
    }
    vector<int> ctN(n + 1);
    vector<int> ctM(m + 1);
    int len = 0;
    int prev = 0;
    for (int i = 0; i < n; ++i) {
        if (prev && a[i]) {
            ++len;
        } else {
            for (int j = len; j; --j) {
                ctN[j] += len - j + 1;
            }
            len = prev = a[i];
        }
    }
    for (int j = len; j; --j) {
        ctN[j] += len - j + 1;
    }
    len = 0;
    prev = 0;
    for (int i = 0; i < m; ++i) {
        if (prev && b[i]) {
            ++len;
        } else {
            for (int j = len; j; --j) {
                ctM[j] += len - j + 1;
            }
            len = prev = b[i];
        }
    }
    for (int j = len; j; --j) {
        ctM[j] += len - j + 1;
    }
    long long sol = 0;
    for (int i = 1; i <= k && i <= n; ++i) {
        if (k % i == 0 && k / i <= m) {
            sol += (long long) ctN[i] * ctM[k / i];
        }
    }
    cout << sol << '\n';
}