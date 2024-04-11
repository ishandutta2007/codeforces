#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        bool ans = true;
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            vector<char> a, b;
            for (int k = -1; k <= 1; ++k) if (k != 0) if (s[i] + k >= 'a' && s[i] + k <= 'z') a.push_back(s[i] + k);
            for (int k = -1; k <= 1; ++k) if (k != 0) if (s[j] + k >= 'a' && s[j] + k <= 'z') b.push_back(s[j] + k);
            bool ok = false;
            for (auto c : a) for (auto d : b) ok |= c == d;
            ans &= ok;
        } 
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}