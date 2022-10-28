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

        long long answer = LLONG_MIN, sum = 0;
        for (int i = 0; i <= n; ++i) {
            long long ext = 0;
            for (int j = i, div = 2; j < n && (div < (1 << 30)); ++j) {
                ext += a[j] / div;
                div *= 2;
            }
            answer = max(answer, sum + ext);
            if (i < n) sum += a[i] - k;
        }

        cout << answer << "\n";
    }
}