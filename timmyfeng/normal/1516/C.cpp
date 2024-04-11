#include <bits/stdc++.h>
using namespace std;

const int N = 100, K = 100 * 2000 + 1;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bitset<K> visited;
    visited[0] = 1;
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        visited |= visited << a[i];
    }

    if (sum % 2 == 0 && visited[sum / 2]) {
        array<int, 2> ans = {K, N};
        for (int i = 0; i < n; ++i) {
            ans = min(ans, array<int, 2>{a[i] & -a[i], i});
        }

        cout << 1 << "\n";
        cout << ans[1] + 1 << "\n";
    } else {
        cout << 0 << "\n";
    }
}