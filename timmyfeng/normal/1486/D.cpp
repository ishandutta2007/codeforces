#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;

int a[N], sum[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int l = 1, r = n;
    while (l < r) {
        int m = (l + r + 1) / 2;

        bool ok = false;
        int prefix = n + 1;
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + (a[i] >= m ? 1 : -1);
            if (i >= k - 1) {
                prefix = min(prefix, sum[i - k + 1]);
            }
            ok |= (sum[i + 1] - prefix > 0);
        }

        if (ok) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    cout << r << "\n";
}