#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string t1 = "one", t2 = "two", t0 = "twone";
        int n = s.size();
        vector<int> ans;
        rep(i, 0, n - 4) {
            if (t0 == s.substr(i, 5)) {
                ans.emplace_back(i + 3);
                s[i + 2] = 'x';
            }
        }
        rep(i, 0, n - 2) {
            string x = s.substr(i, 3);
            if (t1 == x || t2 == x) {
                ans.emplace_back(i + 2);
            }
        }
        cout << ans.size() << endl;
        for (auto x : ans)
            cout << x << ' ';
        cout << endl;
    }
    return 0;
}