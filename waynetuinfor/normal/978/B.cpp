#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < n; ) {
        if (s[i] != 'x') {
            ++i;
            continue;
        }
        int j = i;
        while (j < n && s[j] == 'x') ++j;
        int l = j - i;
        if (l >= 3) ans += l - 2;
        i = j;
    }
    cout << ans << endl;
}