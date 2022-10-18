#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> r, wc, m;
    string c;
    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        if (t == "rat") {
            r.emplace_back(s);
        } else if (t == "man") {
            m.emplace_back(s);
        } else if (t == "captain") {
            c = s;
        } else {
            wc.emplace_back(s);
        }
    }
    r.insert(r.end(), wc.begin(), wc.end());
    r.insert(r.end(), m.begin(), m.end());
    r.emplace_back(c);
    for (auto s : r) {
        cout << s << '\n';
    }
    return 0;
}