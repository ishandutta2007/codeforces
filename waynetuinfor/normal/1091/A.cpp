#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    int ans = 0;
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            for (int k = 1; k <= c; ++k) {
                if (j - i == 1 && k - j == 1) ans = max(ans, i + j + k);
            }
        }
    }
    cout << ans << endl;
}