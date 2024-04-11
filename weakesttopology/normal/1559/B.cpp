#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int N;
        string s;
        cin >> N >> s;
        for (int i = 0; i + 1 < N; ++i) {
            if (s[i + 1] != '?') continue;
            if (s[i] == 'R') s[i + 1] = 'B';
            if (s[i] == 'B') s[i + 1] = 'R';
        }
        for (int i = N - 1; i > 0; --i) {
            if (s[i - 1] != '?') continue;
            if (s[i] == 'R') s[i - 1] = 'B';
            if (s[i] == 'B') s[i - 1] = 'R';
        }
        if (s == string(N, '?')) {
            for (int i = 0; i < N; ++i) {
                s[i] = "RB"[i % 2];
            }
        }
        cout << s << '\n';
    }
    exit(0);
}