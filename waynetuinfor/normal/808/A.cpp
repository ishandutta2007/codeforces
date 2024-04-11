#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != '0') {
            string t = s; t[i]++;
            if (t[i] > '9') t = '1' + t;
            for (int j = i + 1; j < t.length(); ++j) t[j] = '0';
            // cout << t << endl;
            // for (int j = t.length())
            stringstream ss1(s), ss2(t);
            int a, b; ss1 >> a; ss2 >> b;
            return cout << b - a << endl, 0;
        }
    }
    return 0;
}