#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

long long pow2[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    pow2[0] = 1;
    for (int i = 1; i < N; ++i) {
        if (pow2[i - 1] <= LLONG_MAX / 2) {
            pow2[i] = 2 * pow2[i - 1];
        } else {
            pow2[i] = LLONG_MAX;
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        if (k > pow2[n - 1]) {
            cout << -1 << "\n";
            continue;
        }

        int j = 0;
        for (int i = 1; i < n; ++i) {
            if (pow2[n - i - 1] < k) {
                k -= pow2[n - i - 1];
            } else {
                for (int l = i; l > j; --l) {
                    cout << l << " ";
                }
                j = i;
            }
        }

        for (int l = n; l > j; --l) {
            cout << l << " ";
        }

        cout << "\n";
    }
}