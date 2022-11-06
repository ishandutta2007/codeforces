#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int ans = 0;
        while (ans < (int)s.size() && s[ans] == '<') ++ans;
        int ans2 = 0;
        while (ans2 < (int)s.size() && s[(int)s.size() - 1 - ans2] == '>') ++ans2;
        printf("%d\n", min(ans, ans2));
    }
}