#include <iostream>
#include <string>
using namespace std;

string s, t;

string dq(const string&, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s >> t;
    s = dq(s, 0, (int)s.length());
    t = dq(t, 0, (int)t.length());
    if (s == t) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

string dq(const string& ss, int L, int R) {
    if ((R - L) & 1) return ss.substr(L, R - L);
    string a, b;
    int M = (L + R) >> 1;
    a = dq(ss, L, M), b = dq(ss, M, R);
    if (a < b) return a + b;
    return b + a;
}