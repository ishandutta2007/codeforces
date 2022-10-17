#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int cost;
        cin >> cost;
        int n = static_cast<int>(s.size());
        vector<vector<int>> have(26);
        vector<bool> killed(n);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += (s[i] - 'a' + 1);
            have[s[i] - 'a'].push_back(i);
        }
        int ptr = 25;
        while (cur > cost) {
            while (have[ptr].empty()) {
                ptr--;
            }
            killed[have[ptr].back()] = true;
            have[ptr].pop_back();
            cur -= ptr + 1;
        }
        for (int i = 0; i < n; i++) {
            if (!killed[i]) {
                cout << s[i];
            }
        }
        cout << '\n';
    }
    return 0;
}