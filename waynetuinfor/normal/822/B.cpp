#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    vector<int> ans(t.length() + 1); 
    for (int i = 0; i < t.length(); ++i) {
        if (i + s.length() > t.length()) break;
        vector<int> pos;
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] != t[i + j]) pos.push_back(j);
        }
        if (pos.size() < ans.size()) ans = pos;
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i + 1 << ' '; cout << endl;
    return 0;
}