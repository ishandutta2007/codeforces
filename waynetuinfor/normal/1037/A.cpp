#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; ; ++i) {
        if ((1 << i) > n) {
            if (n > 0) ++ans;
            break;
        }
        ans++;
        n -= (1 << i);
    }
    cout << ans << endl;
}