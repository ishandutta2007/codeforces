#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
string v = "aeiouy";
bool vv[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    string ans = "";
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < 6; ++j) if (s[i] == v[j]) vv[i] = true;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (!vv[i]) {
            ans += s[i];
            continue;
        }
        if (i > 0 && vv[i] && vv[i - 1]) continue;
        ans += s[i];
    }
    cout << ans << endl;
    return 0;
}