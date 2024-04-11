#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s, c;
        cin >> s >> c;
        string tmp = s;
        sort(tmp.begin(), tmp.end());
        int i = 0;
        while (i < s.size() && s[i] == tmp[i]) {
            ++i;
        }
        if (i < s.size()) {
            iter_swap(s.begin() + i, s.begin() + s.find_last_of(tmp[i]));
        }
        cout << (s < c ? s : "---") << '\n';
    }
}