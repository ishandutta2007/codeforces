#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

int main() {
    int n, a, b; cin >> n >> a >> b;
    int c = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        if (t == 1) {
            if (a) a--;
            else if (b) --b, ++c;
            else if (c) --c;
            else ++ans;
        } else {
            if (b) --b;
            else ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}