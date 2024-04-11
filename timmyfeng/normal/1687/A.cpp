#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        vector<long long> a(n);
        for (auto &i : a) cin >> i;

        long long len = min(n, k), sum = 0, answer = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= len) sum -= a[i - len];
            sum += a[i];
            answer = max(answer, sum + k * len - (len + 1) * len / 2);
        }

        cout << answer << "\n";
    }
}