#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        long long x;
        string s;
        cin >> n >> k >> x >> s; --x;

        for (int i = n - 1, j = n - 1; i >= 0; i = j) {
            if (s[i] == '*') {
                while (j >= 0 && s[j] == '*') --j;
                int mod = (i - j) * k + 1;
                s = s.substr(0, j + 1) + string(x % mod, 'b') + s.substr(i + 1);
                x /= mod;
            } else {
                j = i - 1;
            }
        }

        cout << s << "\n";
    }
}