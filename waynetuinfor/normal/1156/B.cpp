#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        {
            vector<int> cnt(26, 0);
            string t = "";
            int n = (int)s.size();
            for (int i = 0; i < n; ++i)
                cnt[s[i] - 'a']++;

            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0)
                    t += i + 'a';
            }
            string z = "";
            for (int i = 1; i < (int)t.size(); i += 2)
                z += t[i];
            for (int i = 0; i < (int)t.size(); i += 2)
                z += t[i];

            string ans = "";
            for (int i = 0; i < (int)z.size(); ++i) {
                while (cnt[z[i] - 'a']--)
                    ans += z[i];
            }

            bool pos = true;
            for (int i = 0; i < (int)ans.size() - 1; ++i)
                pos &= abs(ans[i] - ans[i + 1]) != 1;

            if (pos) {
                cout << ans << endl;
                continue;
            }
        }
        {
            vector<int> cnt(26, 0);
            string t = "";
            int n = (int)s.size();
            for (int i = 0; i < n; ++i)
                cnt[s[i] - 'a']++;

            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0)
                    t += i + 'a';
            }
            string z = "";
            for (int i = 0; i < (int)t.size(); i += 2)
                z += t[i];
            for (int i = 1; i < (int)t.size(); i += 2)
                z += t[i];

            string ans = "";
            for (int i = 0; i < (int)z.size(); ++i) {
                while (cnt[z[i] - 'a']--)
                    ans += z[i];
            }

            bool pos = true;
            for (int i = 0; i < (int)ans.size() - 1; ++i)
                pos &= abs(ans[i] - ans[i + 1]) != 1;

            if (pos) {
                cout << ans << endl;
                continue;
            }
        }

        cout << "No answer" << endl;
    }
}