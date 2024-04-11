#include <bits/stdc++.h>
using namespace std;

vector<int> pos[26];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    for (int i = 0; i < (int)s.size(); ++i) pos[s[i] - 'a'].push_back(i);
    while (n--) {
        string t; cin >> t;
        long long ans = 0;
        for (int i = 0; i < (int)t.size(); ++i) {
            if (pos[t[i] - 'a'].empty()) {
                ans += t.size();
                continue;
            }
            auto it = lower_bound(pos[t[i] - 'a'].begin(), pos[t[i] - 'a'].end(), i);
            int add = 1e8;
            if (it != pos[t[i] - 'a'].end()) add = min(add, *it - i);
            if (it != pos[t[i] - 'a'].begin()) add = min(add, i - *prev(it));
            ans += add;
        }
        cout << ans << "\n";
    }
}