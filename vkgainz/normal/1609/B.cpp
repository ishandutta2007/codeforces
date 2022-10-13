#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int t; t = 1;
    while (t--) {
        int n, q; cin >> n >> q;
        string s; cin >> s;
        vector<bool> eq(n);
        for (int i = 2; i < n; i++) {
            eq[i] = s.substr(i - 2, 3) == "abc";
        }
        int ans = accumulate(eq.begin(), eq.end(), 0);
        while (q--) {
            int i; char c; cin >> i >> c;
            --i;
            s[i] = c;
            int ch = 0;
            for (int j = i; j <= i + 2; j++) {
                if (j - 2 >= 0 && j < n) {
                    ch += (s.substr(j - 2, 3) == "abc") - eq[j];
                    eq[j] = s.substr(j - 2, 3) == "abc";
                }
            }
            ans += ch;
            cout << ans << "\n";
        }
    }
}