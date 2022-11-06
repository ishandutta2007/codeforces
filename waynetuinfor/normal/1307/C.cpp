#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    long long ans = 0;
    for (char a = 'a'; a <= 'z'; ++a) {
        for (char b = 'a'; b <= 'z'; ++b) {
            long long res = 0;
            int cnt = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == b) res += cnt;
                if (s[i] == a) cnt++;
            }
            ans = max(ans, res);
            ans = max(ans, 1LL * cnt);
        }
    }
    cout << ans << endl;
}