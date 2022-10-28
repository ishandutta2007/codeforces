#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

int tally[N], a[N], n;

int solve() {
    int low = 1, high = n;
    while (low < high) {
        int mid = (low + high) / 2;

        fill(tally, tally + n + 1, 0);
        for (int i = 1; i <= mid; ++i) {
            ++tally[a[i]];
        }

        for (int i = 1; i <= min(mid, n - mid); ++i) {
            --tally[a[n + 1 - i]];
        }

        bool ok = *min_element(tally, tally + n + 1) >= 0;
        for (int i = mid + 1; i <= n / 2; ++i) {
            ok &= a[i] == a[n + 1 - i];
        }

        if (ok) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++tally[a[i]];
    }

    int odd = 0;
    bool palin = true;
    for (int i = 1; i <= n; ++i) {
        palin &= a[i] == a[n + 1 - i];
        odd += tally[i] % 2;
    }

    if (odd > 1) {
        cout << 0 << "\n";
        exit(0);
    } else if (palin) {
        cout << (long long) n * (n + 1) / 2 << "\n";
        exit(0);
    }

    int left = solve();

    reverse(a + 1, a + n + 1);
    int right = n + 1 - solve();

    int mid = 1;
    while (a[mid] == a[n + 1 - mid]) {
        ++mid;
    }

    cout << (long long) mid * (n + 1 - left + right - mid) << "\n";
}