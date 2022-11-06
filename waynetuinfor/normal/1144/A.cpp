#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    while (q--) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        bool ans = true;
        for (int i = 1; i < (int)s.size(); ++i) 
            ans &= s[i] == s[i - 1] + 1;
        cout << (ans ? "Yes" : "No") << endl;
    }
}