#include <bits/stdc++.h>
using namespace std;

long long m, bst;
int ans;

long long cb(int n) {
    return 1ll * n * n * n;
}

void dfs(int cnt, long long now, long long s) {
    if (now == 0) {
        if (cnt > ans) ans = cnt, bst = s;
        else if (cnt == ans) bst = max(bst, s);
        return;
    }
    long long cb = (long long)pow(now, 1.0 / 3);
    dfs(cnt + 1, now - cb * cb * cb, s + cb * cb * cb);
    if (cb > 1) dfs(cnt + 1, cb * cb * cb - 1 - (cb - 1) * (cb - 1) * (cb - 1), s + (cb - 1) * (cb - 1) * (cb - 1));
}

int main() {
    cin >> m;
    dfs(0, m, 0);
    cout << ans << ' ' << bst << endl;
    return 0;
}