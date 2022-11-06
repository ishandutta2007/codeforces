#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int c = 0, ans = 0;
    for (int i = 0; i < n; ++i) if (s[i] == '8') ++c;
    for (int i = 1; i <= c; ++i) {
        int y = n - i;
        if (y >= i * 10) ans = i;
    }
    cout << ans << endl;
}