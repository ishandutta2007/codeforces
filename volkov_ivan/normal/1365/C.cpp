#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
int p1[N], p2[N];
int wh[N];
int cnt[2 * N];
int n, c;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p1[i];
        wh[p1[i]] = i;
    }
    int ans = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        cin >> p2[i];
        int pos1 = wh[p2[i]];
        int diff = i - pos1;
        if (diff < 0) diff += n;
        ans = max(ans, ++cnt[diff]);
    }
    cout << ans << endl;
}