#include <iostream>
#include <vector>

using namespace std;


int main() {
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        string s; cin >> s;
        vector<int> pref(n + 1);
        pref[0] = 1;
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1];
            int mult = 1;
            if (i % 2 == 0) mult *= -1;
            if (s[i - 1] == '-') mult *= -1;
            pref[i] += mult;
        }
        for (int i = 0; i < q; i++) {
            int l, r; cin >> l >> r;
            int tot = pref[r] - pref[l - 1];
            if (l % 2 == 0) tot *= -1;
            if (tot == 0) cout << 0 << "\n";
            else if (abs(tot) % 2) cout << 1 << "\n";
            else cout << 2 << "\n";
        }
    }
}