#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, d; cin >> n >> d;
    int ind = 0, ans = 0;
    for (int i = 0; i < d; ++i) {
        string s; cin >> s;
        bool full = true;
        for (int j = 0; j < n; ++j) if (s[j] == '0') full = false;
        if (full) ans = max(ans, i - ind), ind = i + 1;
    }
    ans = max(ans, d - ind);
    cout << ans << '\n';
    return 0;
}