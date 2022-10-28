#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;

    for (char c = 'z'; c >= 'b'; --c) {
        bool change;
        do {
            change = false;
            for (int i = 0; i < n; ++i) {
                if (s[i] != c) continue;
                if ((i != 0 && s[i - 1] == c - 1) || (i != n - 1 && s[i + 1] == c - 1)) {
                    s.erase(i, 1);
                    change = true;
                }
            }
        } while (change);
    }
    cout << n - s.size() << '\n';
}