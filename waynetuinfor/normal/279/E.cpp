#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int ans = 0;
    for (int i = s.size() - 1; i >= 0; ) {
        if (s[i] == '0') {
            --i;
            continue;
        }
        if (i > 0 && s[i - 1] == '1') {
            int j = i - 1;
            while (j >= 0 && s[j] == '1') s[j] = '0', --j;
            if (j < 0) ++ans;
            else s[j] = '1';
            i = j;
            continue;
        }
        --i;
    } 
    for (int i = 0; i < s.size(); ++i) ans += (s[i] == '1');
    cout << ans << endl;
}