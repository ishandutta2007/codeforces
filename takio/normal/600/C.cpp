#include <bits/stdc++.h>
using namespace std;

const int N = 210000;
char s[N];
int c[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
//    int n, m, x;
    scanf ("%s", s);
    int n = strlen (s);
    for (int i = 0; s[i]; i++) {
        c[s[i] - 'a']++;
    }
    vector <int> g;
    for (int i = 0; i < 26; i++) if (c[i] & 1) {
        g.push_back (i);
    }
    for (int i = 0; i < g.size() / 2; i++) {
        c[g[i]]++;
        c[g[g.size() - 1 - i]]--;
    }
    string s = "";
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j < c[i]; j += 2) s += ('a' + i);
    }
    string t = s;
    reverse (t.begin (), t.end());
    for (int i = 0; i < 26; i++) if (c[i] & 1) s += ('a' + i);
    s += t;
    cout << s << endl;
}