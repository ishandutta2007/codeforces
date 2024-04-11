#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int ans[maxn];

int main() {
    string s; cin >> s;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] <= s[0]) {
            // cout << "i = " << i << endl;
            // cout << "before = " << s << endl;
            reverse(s.begin(), s.begin() + i);
            reverse(s.begin(), s.begin() + i + 1);
            // cout << "after = " << s << endl;
            ans[i - 1] ^= 1;
            ans[i] ^= 1;
        }
    } 
    for (int i = 0; i < s.size(); ++i) cout << ans[i] << ' '; cout << endl;
}