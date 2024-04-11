#include <bits/stdc++.h>
using namespace std;

string f(string s) {
    string r = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') r += (s[i] - 'A' + 'a');
        else r += s[i];
    }
    return r;
}

int main() {
    string a, b; cin >> a >> b;
    a = f(a), b = f(b);
    if (a < b) cout << "-1";
    if (a > b) cout << "1";
    if (a == b) cout << "0";
}