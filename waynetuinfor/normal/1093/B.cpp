#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        string t = s;
        reverse(t.begin(), t.end());
        if (s == t) cout << -1 << endl;
        else cout << s << endl;
    }
}