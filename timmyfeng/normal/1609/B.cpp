#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    int abcs = 0;
    for (int i = 0; i + 3 <= n; ++i) {
        abcs += (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c');
    }

    while (q--) {
        int pos;
        char c;
        cin >> pos >> c;
        --pos;

        for (int i = max(0, pos - 2); i <= pos && i + 3 <= n; ++i) {
            abcs -= (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c');
        }

        s[pos] = c;

        for (int i = max(0, pos - 2); i <= pos && i + 3 <= n; ++i) {
            abcs += (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c');
        }

        cout << abcs << "\n";
    }
}