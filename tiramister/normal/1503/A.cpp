#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ones = count(s.begin(), s.end(), '1');
    if (ones % 2 != 0 || s.front() == '0' || s.back() == '0') {
        cout << "NO\n";
        return;
    }

    string a, b;
    int zcnt = 0, ocnt = 0;
    for (auto c : s) {
        if (c == '0') {
            a.push_back(zcnt % 2 == 0 ? '(' : ')');
            b.push_back(zcnt % 2 == 0 ? ')' : '(');
            ++zcnt;
        } else {
            char p = (ocnt < ones / 2 ? '(' : ')');
            a.push_back(p);
            b.push_back(p);
            ++ocnt;
        }
    }

    cout << "YES\n"
         << a << "\n"
         << b << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}