#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s;
    int ans = 0;
    while (cin >> s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) if (s[i] >= 'A' && s[i] <= 'Z') ++cnt;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}