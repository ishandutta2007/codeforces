#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int A = 1000001;

    vector<bool> composite(A);
    for (int i = 2; i < A; ++i) {
        if (!composite[i]) {
            for (int j = 2 * i; j < A; j += i) {
                composite[j] = true;
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n, e;
        cin >> n >> e;

        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        vector<int> before(n), after(n);
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                before[i] = (i >= e ? before[i - e] : 0) + 1;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == 1) {
                after[i] = (i + e < n ? after[i + e] : 0) + 1;
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > 1 && !composite[a[i]]) {
                ans += (long long) (i >= e ? before[i - e] + 1 : 1) * 
                    (i + e < n ? after[i + e] + 1 : 1) - 1;
            }
        }

        cout << ans << "\n";
    }
}