#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> c(5);
    for (int i = 0; i < n; ++i) {
        int s; cin >> s;
        ++c[s];
    }
    int ans = c[4];
    int k = min(c[3], c[1]);
    ans += k;
    c[3] -= k; c[1] -= k;
    if (c[3] > 0) ans += c[3], c[3] = 0;
    ans += c[2] / 2, c[2] %= 2;
    if (c[2] && c[1]) ++ans, c[2] = 0, c[1] = max(0, c[1] - 2);
    else if (c[2]) ++ans, c[2] = 0;
    if (c[1] % 4 == 0) ans += c[1] / 4;
    else ans += c[1] / 4 + 1;
    cout << ans << endl;
}