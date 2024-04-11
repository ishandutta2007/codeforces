#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    while(t--) {
        string s, t; cin >> s >> t;
        int n = (int) s.length(), m = (int) t.length();
        vector<int> dp(n + 1);
        dp[n] = m;
        pair<int, int> nxt;
        if(n % 2 == 0)
            nxt = {m, m + 2};
        else
            nxt = {m + 2, m};
        for(int i = n - 1; i >= 0; i--) {
            if(nxt.first == 0 || nxt.second == 0) break;
            if(i % 2 == 0) {
                //go to nxt.second
                if(nxt.second > m) continue;
                if(s[i] == t[nxt.second - 1])
                    nxt.first = min(nxt.first, nxt.second - 1);
            }
            else {
                //go to nxt.first
                if(nxt.first > m) continue;
                if(s[i] == t[nxt.first - 1])
                    nxt.second = min(nxt.second, nxt.first - 1);
            }
        }
        if(nxt.first == 0 || nxt.second == 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}