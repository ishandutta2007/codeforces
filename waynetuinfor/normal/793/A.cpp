#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int tag = *min_element(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if ((a[i] - tag) % k == 0) ans += (a[i] - tag) / k;
        else return cout << "-1\n", 0;
    }
    cout << ans << '\n';
    return 0;
}