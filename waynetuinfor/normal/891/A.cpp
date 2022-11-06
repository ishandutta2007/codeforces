#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10, inf = 1e9 + 1;
int a[maxn];

int main() {
    int n; cin >> n;
    int g = 0, o = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        g = __gcd(g, a[i]);
        if (a[i] == 1) ++o;
    }
    if (g > 1) return cout << "-1" << endl, 0;
    if (o > 0) return cout << n - o << endl, 0;
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        int now = a[i];
        for (int j = i + 1; j < n; ++j) {
            now = __gcd(now, a[j]);
            if (now == 1) ans = min(ans, n + (j - i) - 1);
        } 
    }
    if (ans == inf) ans = -1;
    cout << ans << endl;
    return 0;
}