#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<long long> a(n);
        for (auto &i : a) cin >> i;

        sort(a.begin(), a.end());


        long long answer = LLONG_MIN;
        long long prefix = 0, suffix = accumulate(a.begin(), a.end(), 0LL);

        long long pos_inf = a[0] * (suffix - a[0]) - (a[0] - 1) * (suffix - a[0] + (n - 1) * a[0]);

        for (int i = 0; i < n; ++i) {
            long long t = -a[i];
            long long mst = a[0] * suffix + t * (suffix + (n - i) * a[0]) +
                    a[n - 1] * prefix + t * (prefix + i * a[n - 1]);

            if (i == 0) mst -= a[0] * a[0] + 2 * t * a[0];
            else mst -= a[0] * a[n - 1] + t * (a[0] + a[n - 1]);

            answer = max(answer, mst);

            prefix -= t, suffix += t;
        }

        long long neg_inf = a[n - 1] * (prefix - a[n - 1]) - (a[n - 1] + 1) * (prefix - a[n - 1] + (n - 1) * a[n - 1]); 

        if (answer < pos_inf || answer < neg_inf) {
            cout << "INF\n";
        } else {
            cout << answer << "\n";
        }
    }
}