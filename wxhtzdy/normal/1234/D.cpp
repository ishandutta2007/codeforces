#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<set<int>> a(26);
    auto Get = [&](char c) {
        return (int) (c - 'a');
    };
    for (int i = 0; i < (int) s.length(); i++) {
        a[Get(s[i])].insert(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int foo;
        cin >> foo;
        if (foo == 1) {
            int pos;
            cin >> pos;
            char c;
            cin >> c;
            --pos;
            int ch = Get(s[pos]);
            a[ch].erase(a[ch].find(pos));
            s[pos] = c;
            a[Get(c)].insert(pos);
        } else {
            int l, r;
            cin >> l >> r;
            --l; --r;
            int ans = 0;
            for (int i = 0; i < 26; i++) {
                auto it = a[i].lower_bound(l);
                if (it != a[i].end() && *it <= r && *it >= l) {
                    ans++;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}