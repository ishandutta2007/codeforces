#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

void prefix(int n, string& s) {
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            for (int j = i - 1; j >= 0; j--) {
                s[j] = (i % 2 == j % 2 ? s[i] : 'R' ^ 'B' ^ s[i]);
            }
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        s[i] = (i % 2 ? 'B' : 'R');
    }
}

void suffix(int n, string& s) {
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != '?') {
            for (int j = i + 1; j < n; j++) {
                s[j] = (i % 2 == j % 2 ? s[i] : 'R' ^ 'B' ^ s[i]);
            }
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        prefix(n, s);
        suffix(n, s);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '?') {
                for (int j = i + 1; j < s.size(); j++) {
                    if (s[j] != '?') break;

                    s[j] = (i % 2 == j % 2 ? s[i] : s[i] ^ 'R' ^ 'B');
                }
            }
        }

        cout << s << '\n';
    }
}