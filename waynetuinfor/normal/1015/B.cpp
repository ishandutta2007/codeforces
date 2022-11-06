#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    string ss = s, tt = t;
    sort(ss.begin(), ss.end()), sort(tt.begin(), tt.end());
    if (ss != tt) {
        cout << "-1" << endl;
        return 0;
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int p = -1;
        for (int j = i; j < n && p == -1; ++j) 
            if (s[j] == t[i]) p = j;
        while (p > i) ans.push_back(p), swap(s[p], s[p - 1]), --p;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}