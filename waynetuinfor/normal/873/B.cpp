#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int cnt[maxn], b[maxn << 1];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; string s; cin >> n >> s; s = "." + s;
    fill(b, b + (maxn << 1), maxn + 1);
    b[maxn] = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cnt[i] = cnt[i - 1];
        if (s[i] == '1') ++cnt[i];
        int dlt = cnt[i] - (i - cnt[i]);
        ans = max(ans, i - b[dlt + maxn]);
        b[dlt + maxn] = min(b[dlt + maxn], i);
    }
    cout << ans << endl;
    return 0;
}