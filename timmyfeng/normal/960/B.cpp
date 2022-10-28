#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, k0;
    cin >> n >> k >> k0;
    k += k0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        a[i] = abs(a[i] - b);
    }

    for (int i = 0; i < k; ++i) {
        int j = max_element(a, a + n) - a;
        a[j] = abs(a[j] - 1);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (long long) a[i] * a[i];
    }

    cout << ans << "\n";
}