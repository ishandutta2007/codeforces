#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

long long a[2 * N], b[4 * N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        b[i] -= m;
    }

    sort(a, a + n);
    sort(b, b + n);

    for (int i = n; i < 2 * n; ++i) {
        a[i] = a[i - n] + m;
    }

    for (int i = n; i < 4 * n; ++i) {
        b[i] = b[i - n] + m;
    }

    long long low = 0, high = m / 2;
    while (low < high) {
        long long mid = (low + high) / 2;
        bool ok = true;

        int prefix = INT_MAX;
        for (int i = 0, l = 0, r = 0; i < 2 * n; ++i) {
            while (l < 4 * n && b[l] < a[i] - mid) {
                ++l;
            }
            prefix = min(prefix, i - l);

            while (r < 4 * n && b[r] <= a[i] + mid) {
                ++r;
            }
            ok &= i + 1 - r - prefix <= 0;
        }

        if (ok) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << "\n";
}