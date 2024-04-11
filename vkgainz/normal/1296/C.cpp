#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

long long dp[2001][2001];

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        map<pair<int, int>, int> pref;
        pref[make_pair(0, 0)] = 0;
        int x = 0, y = 0;
        int ans = n + 1;
        int l = 0, r = 0;
        for (int i = 0; i < s.length(); i++) {
            int curr = i + 1;
            if (s[i] == 'L') --x;
            if (s[i] == 'R') ++x;
            if (s[i] == 'U') ++y;
            if (s[i] == 'D') --y;
            if (pref.find(make_pair(x, y)) != pref.end()) {
                int cmp = curr - pref[make_pair(x, y)];
                if (cmp < ans) {
                    ans = cmp;
                    l = pref[make_pair(x, y)] + 1;
                    r = curr;
                }
            }
            pref[make_pair(x, y)] = i + 1;
        }
        if (ans == n + 1) cout << -1 << "\n";
        else cout << l << " " << r << "\n";
    }
}