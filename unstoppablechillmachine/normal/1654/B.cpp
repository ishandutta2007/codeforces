#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

signed main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        vector<int> cnt(26);
        for (auto it : s) {
            cnt[it - 'a']++;
        }
        int ptr = 0;
        while (ptr < SZ(s) && cnt[s[ptr] - 'a'] > 1) {
            cnt[s[ptr] - 'a']--;
            ptr++;
        }
        for (int i = ptr; i < SZ(s); i++) {
            cout << s[i];
        }
        cout << '\n';
    }
}