#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int o = 0, k = 0, ans = 0;
    for (int i = 1; i <= n; ++i) cin >> s[i], k += s[i];
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 0) ++o;
        ans = max(ans, k + o);
        if (s[i] == 1) --k;
    }
    cout << ans << endl;
    return 0;
}