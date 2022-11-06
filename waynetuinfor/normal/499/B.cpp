#include <bits/stdc++.h>
using namespace std;

map<string, string> dic1, dic2;
int n, m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        string s, t;
        cin >> s >> t;
        dic1[s] = t, dic2[t] = s;
    }
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        if (dic1.find(s) != dic1.end()) {
            string t = dic1[s];
            if (s.length() < t.length()) cout << s << ' ';
            else if (s.length() > t.length()) cout << t << ' ';
            else cout << s << ' ';
        } else {
            string t = dic2[s];
            if (s.length() < t.length()) cout << s << ' ';
            else if (s.length() > t.length()) cout << t << ' ';
            else cout << t << ' ';
        }
    }
    return 0;
}