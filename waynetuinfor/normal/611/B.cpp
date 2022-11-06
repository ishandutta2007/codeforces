#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b; cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < 62; ++i) {
        for (int j = 0; j < i - 1; ++j) {
            long long k = (1ll << i) - 1 - (1ll << j);
            if (k >= a && k <= b) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}