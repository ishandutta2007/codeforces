#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];
map<int, int> mp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n); reverse(a, a + n);
    for (int i = 0; i < n; ++i) ++mp[a[i]];
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        --mp[a[i]];
        long long d = 1LL; while (d <= a[i]) d <<= 1; d <<= 1;
        while (d >>= 1) {
            if (d - a[i] == a[i]) ans += mp[a[i]];
            else ans += mp[d - a[i]];
        }
    }
    cout << ans << endl;
}