#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<int> h(2 * n + 1);
        for (int i = 0; i < 2 * n; ++i) {
            h[i + 1] = h[i] + (s[i] == '(' ? 1 : -1);
        }

        if (*min_element(h.begin(), h.end()) == 0) {
            cout << 0 << "\n";
            continue;
        }

        int l = 0;
        for (int i = 1; h[i] >= 0; ++i) {
            if (h[i] > h[l]) l = i;
        }

        int r = 2 * n;
        for (int i = 2 * n; h[i] >= 0; --i) {
            if (h[i] > h[r]) r = i;
        }

        int m = max_element(h.begin(), h.end()) - h.begin();

        if (h[m] > h[l] + h[r]) {
            cout << 2 << "\n";
            cout << l + 1 << " " << m << "\n";
            cout << m + 1 << " " << r << "\n";
        } else {
            cout << 1 << "\n";
            cout << l + 1 << " " << r << "\n";
        }
    }
}