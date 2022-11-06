#include <bits/stdc++.h>
using namespace std;

string v = "aeiou", d = "02468", a = "13579";

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        bool vo = false, di = false, c = false, aa = false;;
        for (int j = 0; j < 5; ++j) {
            if (s[i] == v[j]) vo = true;
            if (s[i] == d[j]) di = true;
            if (s[i] == a[j]) aa = true;
            if (s[i] >= 'a' && s[i] <= 'z') c = true;
        }
        if (vo) ++ans;
        else if (aa) ++ans;
    }
    cout << ans << endl;
}