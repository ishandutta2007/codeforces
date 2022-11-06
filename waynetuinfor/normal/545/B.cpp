#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s, t; cin >> s >> t;
    vector<int> diff;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != t[i]) diff.push_back(i);
    }
    if (diff.size() & 1) return cout << "impossible" << endl, 0;
    int cur = 0;
    string p = "";
    int ind = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (ind < diff.size() && i == diff[ind]) {
            if (cur == 0) p += s[i];
            else p += t[i];
            cur ^= 1; ++ind;
        } else {
            p += s[i];
        }
    }
    cout << p << endl;
    return 0;
}