#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n; m = n;
    char cur = 'a';
    for (int i = 0; i + 1 < n; i += 2) {
        cout << cur << cur;
        cur = cur == 'a' ? 'b' : 'a';
        m -= 2;
    }
    while (m--) cout << cur;
    return 0;
}