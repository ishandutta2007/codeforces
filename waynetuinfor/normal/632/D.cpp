#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int cnt[maxn], a[maxn], an[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < maxn) ++cnt[a[i]];
    }
    if (m == 1 && cnt[1] == 0) {
        cout << 1 << ' ' << 0 << endl;
        return 0;
    }
    int ans = 0, num = 1;
    for (int i = 1; i <= m; ++i) {
        int cur = i;
        while (cur < maxn) an[cur] += cnt[i], cur += i;
    }
    for (int i = 1; i <= m; ++i) {
        if (an[i] > ans) ans = an[i], num = i;
    }
    cout << num << ' ' << ans << endl;
    for (int i = 0; i < n; ++i) if (num % a[i] == 0) cout << i + 1 << ' '; cout << endl;
    return 0;
}