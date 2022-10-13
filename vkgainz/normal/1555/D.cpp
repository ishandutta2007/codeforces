#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vector<int>> pref(n + 1, vector<int>(6));
    vector<array<char, 3>> sto(6);
    sto[0] = {'a', 'b', 'c'};
    sto[1] = {'a', 'c', 'b'};
    sto[2] = {'b', 'a', 'c'};
    sto[3] = {'b', 'c', 'a'};
    sto[4] = {'c', 'a', 'b'};
    sto[5] = {'c', 'b', 'a'};
    for(int j = 0; j < 6; j++) {
        vector<int> bad(n + 1);
        for(int i = 1; i <= n; i += 3) {
            if(s[i - 1] != sto[j][0])
                ++bad[i];
        }
        for(int i = 2; i <= n; i += 3) {
            if(s[i - 1] != sto[j][1])
                ++bad[i];
        }
        for(int i = 3; i <= n; i += 3)
            if(s[i - 1] != sto[j][2])
                ++bad[i];
        for(int i = 1; i <= n; i++)
            pref[i][j] = pref[i - 1][j] + bad[i];
    }
    while(m--) {
        int l, r; cin >> l >> r;
        int ans = 1e9;
        for(int typ = 0; typ < 6; typ++) {
            ans = min(ans, pref[r][typ] - pref[l - 1][typ]);
        }
        cout << ans << "\n";
    }
}