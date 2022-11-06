#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    while (n--) {
        int x, c = 0; for (int i = 0; i < 3; ++i) cin >> x, c += x;
        if (c >= 2) ++ans;
    } 
    cout << ans << endl;
}