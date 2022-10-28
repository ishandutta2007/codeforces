#include <bits/stdc++.h>
using namespace std;

void rev(string& s, int a, int b) {
    for (int i = a, j = b; i < j; ++i, --j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        vector<int> ans(n);
        int i = 0;
        for ( ; k > 1; ++i) {
            if (i % 2) {
                ans[i] = find(s.begin() + i, s.end(), ')') - s.begin();
                rev(s, i, ans[i]);
                --k;
            } else {
                ans[i] = find(s.begin() + i, s.end(), '(') - s.begin();
                rev(s, i, ans[i]);
            }
        }
        int stk = 0;
        int ct = n - i;
        for (int j = 0; j < ct; ++i, ++j) {
            if (j >= ct / 2) {
                ans[i] = find(s.begin() + i, s.end(), ')') - s.begin();
                rev(s, i, ans[i]);
            } else {
                ans[i] = find(s.begin() + i, s.end(), '(') - s.begin();
                rev(s, i, ans[i]);
            }
        }
        cout << n << '\n';
        for (int i = 0; i < n; ++i) {
            cout << i + 1 << ' ' << ans[i] + 1 << '\n';
        }
    }
}