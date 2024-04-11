#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); ) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ++i;
            continue;
        }
        vector<int> c(26);
        int j = i, cur = 0;
        for (j; j < s.length(); ++j) {
            if (s[j] >= 'A' && s[j] <= 'Z') break;
            ++c[s[j] - 'a'];
        }
        for (int k = 0; k < 26; ++k) if (c[k]) ++cur;
        ans = max(ans, cur);
        i = j;
    }
    cout << ans << endl;
}