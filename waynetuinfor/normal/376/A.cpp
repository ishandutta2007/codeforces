#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int pos = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '^') pos = i;
    }
    int l = 0, r = 0;
    for (int i = 0; i < pos; ++i) {
        if (s[i] == '=') continue;
        else l += (s[i] - '0') * (pos - i);
    }
    for (int i = pos + 1; i < s.length(); ++i) {
        if (s[i] == '=') continue;
        else r += (s[i] - '0') * (i - pos);
    }
    if (l == r) cout << "balance" << endl;
    else if (l > r) cout << "left" << endl;
    else cout << "right" << endl;
}