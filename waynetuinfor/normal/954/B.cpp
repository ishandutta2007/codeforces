#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 1;
int main() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = n;
    for (int i = 1; i <= n; ++i) {
        string t = "";
        int c = 0;
        for (int j = 0; j < i; ++j) t += s[j], ++c;
        t += t; ++c;
        if (t.size() > s.size()) break;
        for (int j = 0; j < t.size(); ++j) {
            if (s[j] != t[j]) c = inf;
        }
        int k = t.size();
        for (int j = k; j < s.size(); ++j) t += s[j], ++c;
        ans = min(ans, c);
    }
    cout << ans << endl;
}