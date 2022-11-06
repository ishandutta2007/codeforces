#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
string s[maxn];
 
bool check(string s, string t) {
    for (int i = 0; i < t.size(); ++i) {
        if (i + s.size() > t.size()) return false;
        if (t.substr(i, s.size()) == s) return true;
    }    
    return false;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    sort(s, s + n, [](const string &i, const string &j) { return i.size() < j.size(); });
    for (int i = 1; i < n; ++i) {
        if (!check(s[i - 1], s[i])) return 0 * puts("NO");
    }
    puts("YES");
    for (int i = 0; i < n; ++i) cout << s[i] << endl;
    return 0;
}