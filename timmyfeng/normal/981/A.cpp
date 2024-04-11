#include <bits/stdc++.h>
using namespace std;

bool palin(string s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    for (int i = n; i > 0; --i) {
        for (int j = 0; j + i <= n; ++j) {
            if (!palin(s.substr(j, i))) {
                cout << i << "\n";
                exit(0);
            }
        }
    }

    cout << 0 << "\n";
}