#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    stringstream ss(s.substr(0, 2));
    int a; ss >> a;
    ss.clear(); ss.str(s.substr(3, 2));
    int b; ss >> b;
    string t = s; reverse(t.begin(), t.end());
    if (t == s) return cout << 0 << endl, 0;
    for (int i = 0; i < 24; ++i) {
        for (int j = 0; j < 60; ++j) {
            int aa = (a + i) % 24, bb = (b + j) % 60;
            if (b + j >= 60) aa = (aa + 1) % 24;
            string s1, s2;
            ss.clear(); ss.str(""); ss << aa; ss >> s1;
            if (s1.length() == 1) s1 = "0" + s1;
            ss.clear(); ss.str(""); ss << bb; ss >> s2;
            if (s2.length() == 1) s2 = "0" + s2;
            string sss = s1 + s2;
            string t = sss;
            reverse(t.begin(), t.end());
            if (sss == t) return cout << 60 * i + j << endl, 0;
        }
    }
    return 0;
}