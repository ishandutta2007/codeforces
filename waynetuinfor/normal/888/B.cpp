#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int l = 0, r = 0, d = 0, u = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') ++l;
        if (s[i] == 'R') ++r;
        if (s[i] == 'U') ++u;
        if (s[i] == 'D') ++d;
    }
    cout << min(l, r) * 2 + min(d, u) * 2 << endl;
}