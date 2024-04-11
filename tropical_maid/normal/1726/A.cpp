#include <bits/stdc++.h>

using namespace std;

int n, A[2005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int p = 1000, s = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
            if (i > 1) s = max(s, A[i]);
            if (i < n) p = min(p, A[i]);
        }
        int mx = max(s - A[1], A[n] - p);
        for (int i = 1; i <= n; ++i) {
            mx = max(mx, A[i] - A[i % n + 1]);
        }
        printf("%d\n", mx);
    }
    return 0;
}