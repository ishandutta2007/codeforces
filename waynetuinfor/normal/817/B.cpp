#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];
map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i], m[a[i]]++;
    sort(a, a + n);
    int x = a[0], y = a[1], z = a[2];
    long long ans = 0;
    if (x == y && y == z) ans = (long long)m[x] * (long long)(m[x] - 1) * (long long)(m[x] - 2) / (long long)6;
    else if (x == y) ans = (long long)m[z] * (long long)m[x] * (long long)(m[x] - 1) / (long long)2;
    else if (y == z) ans = (long long)m[x] * (long long)m[y] * (long long)(m[y] - 1) / (long long)2;
    else ans = (long long)m[x] * (long long)m[y] * (long long)m[z];
    cout << ans << endl;
    return 0;
}