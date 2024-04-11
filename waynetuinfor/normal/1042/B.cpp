#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
long long a[8];

int main() {
    for (int i = 0; i < 8; ++i) a[i] = inf;
    int n; cin >> n;
    a[0] = 0;
    for (int i = 0; i < n; ++i) {
        int c; cin >> c;
        string s; cin >> s;
        int m = 0;
        for (int j = 0; j < s.size(); ++j) m |= (1 << (s[j] - 'A'));
        a[m] = min(a[m], 1ll * c);
    }
    long long ans = inf;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (int k = 0; k < 8; ++k) {
                int x = (i | j | k);
                if (x != 7) continue;
                ans = min(ans, a[i] + a[j] + a[k]);
            }
        }
    }
    if (ans == inf) {
        cout << "-1" << endl;
    } else {
        cout << ans << endl;
    }
}