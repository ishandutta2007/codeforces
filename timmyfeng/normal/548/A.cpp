#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    string s;
    cin >> s >> k;

    if (s.size() % k != 0) {
        cout << "NO\n";
        exit(0);
    }

    int m = s.size() / k;
    for (int i = 0; i < (int) s.size(); i += m) {
        for (int j = 0; j < m; ++j) {
            if (s[i + j] != s[i + m - 1 - j]) {
                cout << "NO\n";
                exit(0);
            }
        }
    }

    cout << "YES\n";
}