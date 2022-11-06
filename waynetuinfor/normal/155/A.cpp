#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a, b; cin >> a; b = a;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        int c; cin >> c;
        if (c > a || c < b) ++ans;
        a = max(c, a); b = min(c, b);
    }
    cout << ans << endl;
}