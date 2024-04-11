#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> v(n);
    for (auto &i : v) cin >> i;

    for (int i = n - k; i < n; ++i)
        if (v[i] > 0) {
            cout << 0 << "\n";
            return;
        }

    long long answer = 1;
    for (int i = 1; i <= k; ++i) answer = answer * i % M;

    for (int i = 0; i < n - k; ++i) {
        if (v[i] == 0) answer = answer * (k + 1) % M;
        else if (v[i] == -1) answer = answer * (k + 1 + i) % M;
    }

    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}