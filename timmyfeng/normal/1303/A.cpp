#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ndx = 0;
        while (ndx < s.size() && s[ndx] != '1') {
            ndx++;
        }
        int ct = 0;
        int sol = 0;
        for (int i = ndx; i < s.size(); i++) {
            if (s[i] == '0') ct++;
            if (s[i] == '1') sol = ct;
        }
        cout << sol << '\n';
    }
}