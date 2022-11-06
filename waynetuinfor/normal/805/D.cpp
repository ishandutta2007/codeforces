#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int n = (int)s.length();
    int a = 0, ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'a') {
            ans = (ans + a) % mod;
            a = a * 2 % mod;
        } else ++a;
    }    
    cout << ans << endl;
    return 0;
}