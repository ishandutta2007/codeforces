#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> a(n), left(n, n), right(n, -1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i]; --a[i];
        left[a[i]] = min(left[a[i]], i);
        right[a[i]] = max(right[a[i]], i);
    }

    int ans = 0;
    int l = -1, r = -1;
    while (r < n - 1) {
        if (l == r) {
            ++l; r = right[a[l]];
            ans += (l == r ? 1 : 2);
        } else {
            int r_new = -1;
            for (int i = l + 1; i < r; ++i) {
                r_new = max(r_new, right[a[i]]);
            }

            l = r;
            if (r_new > r) {
                r = r_new;
                ++ans;
            }
        }
    }

    cout << n - ans << "\n";
}