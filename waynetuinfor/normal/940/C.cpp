#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    char mx = 'a', mn = 'z';
    for (int i = 0; i < n; ++i) mx = max(mx, s[i]), mn = min(mn, s[i]);
    vector<char> v;
    for (int i = 0; i < n; ++i) v.push_back(s[i]);
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    if (k > n) {
        cout << s;
        for (int i = 0; i < k - n; ++i) cout << mn;
        cout << endl;
        return 0;
    }
    int last = k - 1;
    while (last >= 0 && s[last] == mx) --last; 
    string ans = "";
    for (int i = 0; i < k; ++i) {
        if (i < last) ans += s[i];
        else {
            char to;
            for (int j = 0; j < v.size(); ++j) if (v[j] > s[i]) { to = v[j]; break; }
            ans += to;
            for (int j = i + 1; j < k; ++j) ans += mn;
            cout << ans << endl;
            return 0;
        }
    }
}