#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int cnt[2][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s; s = "." + s;
    for (int i = 1; i < s.length(); ++i) {
        cnt[1][i] = cnt[1][i - 1]; cnt[0][i] = cnt[0][i - 1];
        if (s[i] >= 'A' && s[i] <= 'Z') ++cnt[1][i];
        else ++cnt[0][i];
    }
    if (cnt[0][s.length() - 1] == 0 || cnt[1][s.length() - 1] == 0) return cout << "0" << endl, 0;
    int ans = min(cnt[0][s.length() - 1], cnt[1][s.length() - 1]);
    for (int i = 1; i < s.length(); ++i) {
        ans = min(ans, cnt[0][i] - cnt[0][0] + cnt[1][s.length() - 1] - cnt[1][i]);
    }
    cout << ans << endl;
}