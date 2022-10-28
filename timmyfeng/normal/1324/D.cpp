#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto& i : a) {
        cin >> i;
    }
    for (auto& i : b) {
        cin >> i;
    }
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] - b[i];
    }
    sort(c.begin(), c.end());

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += c.end() - upper_bound(c.begin(), c.end(), b[i] - a[i]);
        if (a[i] - b[i] > b[i] - a[i]) {
            --ans;
        }
    }
    cout << ans / 2;
}