#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
string s[maxn];

int main() {
    int r, c; cin >> r >> c;
    for (int i = 0; i < r; ++i) cin >> s[i];
    int ans = 0;
    for (int i = 0; i < c; ) {
        if (s[r - 1][i] == '.') { ++i; continue; }
        while (i < c && s[r - 1][i] == 'B') ++i;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}