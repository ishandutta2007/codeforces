#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> ndx(n + 1);
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            ndx[a] = i;
        }

        int mx = 0;
        long long sol = 0;
        for (int i = 0; i < m; i++) {
            int b;
            cin >> b;
            if (ndx[b] < mx) {
                sol++;
            } else {
                sol += 2LL * (ndx[b] - i) - 1;
                mx = ndx[b];
            }
        }
        cout << sol << '\n';
    }
}