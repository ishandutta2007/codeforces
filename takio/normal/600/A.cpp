#include <bits/stdc++.h>
using namespace std;

int jug (string s) {
    if (s.length() != 1 && s[0] == '0') return 0;
    for (int i = 0; s[i]; i++) if (s[i] < '0' || s[i] > '9') return 0;
    return 1;
}

vector <string> a, b;

void w (vector <string> a) {
    if (a.size() == 0) { cout << '-' << endl; return; }
    for (int i = 0; i < a.size(); i++) {
        if (i == 0) cout << '"';
        else cout << ',';
        cout << a[i];
    }
    cout << '"' << endl;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    char ch;
    string s = "";
    while (1) {
        ch = getchar ();
//        cout << ch << endl;
        if (ch == '\n') continue;
        if (ch == EOF || ch == ',' || ch == ';' || ch == '\n') {
            if (s != "" && jug (s)) a.push_back (s);
            else b.push_back (s);
            s = "";
        } else s += ch;
        if (ch == EOF) break;
    }
    w (a);
    w (b);
}