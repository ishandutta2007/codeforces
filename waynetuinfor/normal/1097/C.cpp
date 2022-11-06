#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
string s[maxn];
int a[maxn], b[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    int c = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0, x = 1e9;
        bool ok = true;
        for (int j = 0; j < s[i].size(); ++j) {
            if (s[i][j] == '(') ++cnt;
            else --cnt;
            if (cnt < 0) ok = false;
            x = min(x, cnt);
        }
        if (!ok) {
            if (cnt >= 0) continue;
            if (x >= cnt) ++b[-cnt];
        } else {
            if (cnt == 0) ++c;
            ++a[cnt];
        }
    }
    int ans = c / 2;
    for (int i = 0; i < maxn; ++i) ans += min(a[i], b[i]);
    cout << ans << endl;
}