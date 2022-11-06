#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t; cin >> s >> t;
    string ans = s;
    int ind = ans.length() - 1;
    while (ind >= 0 && ans[ind] == 'z') --ind;
    if (ind == -1) return cout << "No such string\n", 0;
    ans[ind]++; for (int i = ind + 1; i < ans.length(); ++i) ans[i] = 'a';
    if (ans >= t) cout << "No such string\n";
    else cout << ans << endl;
    return 0;
}