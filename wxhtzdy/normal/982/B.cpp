#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    multiset<pair<int, int>> p;
    multiset<pair<int, int>> k;
    for (int i = 0; i < n; i++) {
        p.insert({a[i], i + 1});
    }
    vector<int> ans(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '0') {
            auto c = *p.begin();
            ans[i] = c.second;
            k.insert(c);
            p.erase(p.begin());
        } else {
            auto c = *k.rbegin();
            ans[i] = c.second;
            auto it = k.end();
            --it;
            k.erase(it);
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}