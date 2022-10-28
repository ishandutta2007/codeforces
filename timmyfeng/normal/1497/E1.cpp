#include <bits/stdc++.h>
using namespace std;

const int A = 10000000 + 1;
const int N = 200000;

int sieve[A];
int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i < A; ++i) {
        if (sieve[i] == 0) {
            for (int j = i; j < A; j += i) {
                sieve[j] = i;
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i] = 1;
            while (x > 1) {
                if (a[i] % sieve[x] == 0) {
                    a[i] /= sieve[x];
                } else {
                    a[i] *= sieve[x];
                }
                x /= sieve[x];
            }
        }

        int ans = 1;
        set<int> values;
        for (int i = 0; i < n; ++i) {
            if (values.count(a[i]) > 0) {
                values.clear();
                ++ans;
            }
            values.insert(a[i]);
        }

        cout << ans << "\n";
    }
}