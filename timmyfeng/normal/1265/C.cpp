#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> p;
    while (t--) {
        int n;
        cin >> n;
        p.resize(n);
        for (auto& i : p) {
            cin >> i;
        }

        int g = 0, s = 0, b = 0;
        for (int i = 1; i <= n / 2; ++i) {
            bool sw = (p[i] != p[i - 1]);
            if (!g) {
                if (sw) {
                    g = i;
                }
            } else if (!s) {
                if (i - g > g && sw) {
                    s = i - g;
                }
            } else {
                if (i - (g + s) > g && sw) {
                    b = i - (g + s);
                }
            }
        }
        if (!b) {
            g = s = b;
        }
        cout << g << ' ' << s << ' ' << b << '\n';
    }
}