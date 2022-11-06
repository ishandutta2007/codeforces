#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int c00 = 0, c01 = 0, c10 = 0, c11 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '0' && b[i] == '0') ++c00;
        if (a[i] == '0' && b[i] == '1') ++c01;
        if (a[i] == '1' && b[i] == '0') ++c10;
        if (a[i] == '1' && b[i] == '1') ++c11;
    }
    long long ans = c00 * 1ll * c11 + c00 * 1ll * c10 + c01 * 1ll * c10;
    cout << ans << endl;
}