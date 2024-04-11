#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long ans = 0;
    int n; cin >> n; while (n--) {
        string s; cin >> s;
        if (s[0] == 'T') ans += 4;
        if (s[0] == 'C') ans += 6;
        if (s[0] == 'O') ans += 8;
        if (s[0] == 'D') ans += 12;
        if (s[0] == 'I') ans += 20;
    }
    cout << ans << '\n';
    return 0;
}