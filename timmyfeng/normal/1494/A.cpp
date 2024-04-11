#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        bool ok = false;
        for (int i = 0; i < (1 << 3) && !ok; ++i) {
            ok = true;
            int balance = 0;
            for (int j = 0; j < (int) s.size(); ++j) {
                if ((i & (1 << (s[j] - 'A'))) > 0) {
                    ++balance;
                } else {
                    --balance;
                }
                ok &= balance >= 0;
            }
            ok &= balance == 0;
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
}