#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
string s[maxn];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
        if (s[i][0] == 'O' && s[i][1] == 'O') {
            s[i][0] = s[i][1] = '+';
            cout << "YES" << endl;
            for (int j = 0; j < n; ++j) cout << s[j] << endl;
            return 0;
        }
        if (s[i][3] == 'O' && s[i][4] == 'O') {
            s[i][3] = s[i][4] = '+';
            cout << "YES" << endl;
            for (int j = 0; j < n; ++j) cout << s[j] << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}