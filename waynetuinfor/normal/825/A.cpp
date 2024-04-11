#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; string s; cin >> n >> s;
    assert(s[0] == '1');
    for (int i = 0; i < n; ) {
        if (s[i] == '1') {
            int cnt = 0, ind = i;;
            while (ind < n && s[ind] == '1') ++ind, ++cnt;
            cout << cnt; i = ind;
        } else {
            int cnt = 0, ind = i;
            while (ind < n && s[ind] == '0') ++ind, ++cnt;
            while (cnt-- > 1) cout << 0; i = ind;
        }
    }
    if (s[n - 1] == '0') cout << 0;
    return 0;
}