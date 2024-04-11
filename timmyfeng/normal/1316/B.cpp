#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        string best = s;
        int sol = 1;
        for (int k = 1; k <= n; ++k) {
            string t = s.substr(k - 1);
            string tmp = s.substr(0, k - 1);
            if ((s.size() - k) % 2 == 0) {
                reverse(tmp.begin(), tmp.end());
            }
            t += tmp;
            if (t < best) {
                best = t;
                sol = k;
            }
        }
        cout << best << '\n';
        cout << sol << '\n';
    }
}