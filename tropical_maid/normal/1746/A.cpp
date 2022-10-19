#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k, s = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            int a;
            cin >> a;
            s += a;
        }
        printf(s ? "YES\n" : "NO\n");
    }
    return 0;
}