#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        string s;
        cin >> n >> x >> s;

        vector<int> ps(n + 1);
        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i - 1] + (s[i - 1] == '0' ? 1 : -1);
        }

        int sol = 0;
        if (ps[n] == 0) {
            if (find(ps.begin(), ps.end(), x) != ps.end()) {
                sol = -1;
            }
        } else {
            for (int i = 0; i < n; i++) {
                sol += ((x - ps[i]) % ps[n] == 0 && (x - ps[i]) / ps[n] >= 0);
            }
        }
        cout << sol << '\n';
    }
}