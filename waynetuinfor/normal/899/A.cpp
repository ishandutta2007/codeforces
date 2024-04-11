#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], c[3];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++c[a[i]];
    }
    int ans = min(c[2], c[1]);
    c[1] -= ans;
    ans += c[1] / 3;
    cout << ans << endl;
    return 0;
}