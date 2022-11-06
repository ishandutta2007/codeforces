#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    set<int> pos;
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == '4' && s[i + 1] == '7') pos.insert(i);
    }
    while (k > 0) {
        if (pos.size() == 0) {
            cout << s << endl;
            return 0;
        }
        auto it = pos.begin();
        pos.erase(it);
        int p = *it;
        if (p > 0 && p % 2 == 1 && s[p - 1] == '4') {
            if (k & 1) s[p] = '7';
            cout << s << endl;
            return 0;
        }
        if (p + 2 < n && p % 2 == 0 && s[p + 2] == '7') {
            if (k & 1) s[p + 1] = '4';
            cout << s << endl;
            return 0;
        }
        if (p % 2 == 1) s[p] = '7';
        else s[p + 1] = '4';
        --k;
    }
    cout << s << endl;
    return 0;
}