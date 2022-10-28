#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        sort(s.begin(), s.end());
        bool ok = false;
        for (int i = 0; i + s.size() <= t.size() && !ok; ++i) {
            string tmp = t.substr(i, s.size());
            sort(tmp.begin(), tmp.end());
            ok = (s == tmp);
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}