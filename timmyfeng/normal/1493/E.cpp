#include <bits/stdc++.h>
using namespace std;

bool decrease(string &s) {
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '0') {
        --i;
    }

    if (i == -1) {
        return false;
    }

    s[i] = '0';
    fill(s.begin() + i + 1, s.end(), '1');
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s, t;
    cin >> n >> s >> t;

    if (n == 1) {
        cout << t << "\n";
        exit(0);
    }

    string x(n, '0');
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != t[i]) {
            x = string(i, '0') + string(n - i, '1');
            break;
        }
    }

    decrease(s);

    string u = t;
    bool one = false, zero = false;
    while (u >= s && (!one || !zero)) {
        zero |= u.substr(n - 2) == "11";
        one |= u.substr(n - 2) == "01";
        if (!decrease(u)) {
            break;
        }
    }

    string y = t;
    if (y[n - 2] == '0') {
        y.back() = one ? '1' : '0';
    } else {
        y.back() = zero ? '1' : '0';
    }

    cout << max(x, y) << "\n";
}