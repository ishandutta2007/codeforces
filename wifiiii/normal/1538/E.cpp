#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string, string> pre, suf;
map<string, ll> dp;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        pre.clear();
        suf.clear();
        dp.clear();
        int n;
        cin >> n;
        string last;
        for(int i = 1; i <= n; ++i) {
            string a, b, c;
            cin >> a >> b >> c;
            if(b == "=") {
                string d, e;
                cin >> d >> e;
                assert(d == "+");
                int tmp = 0;
                for(int j = 1; j < 4; ++j) {
                    if(suf[c].size() < j || pre[e].size() < 4 - j) continue;
                    if(suf[c].substr(suf[c].size() - j) + pre[e].substr(0, 4 - j) == "haha") {
                        tmp += 1;
                    }
                }
                assert(dp.count(c));
                assert(dp.count(e));
                dp[a] = dp[c] + dp[e] + tmp;
                pre[a] = pre[c] + pre[e];
                suf[a] = suf[c] + suf[e];
                if(pre[a].size() > 4) {
                    pre[a] = pre[a].substr(0, 4);
                }
                if(suf[a].size() > 4) {
                    suf[a] = suf[a].substr(suf[a].size() - 4);
                }
            } else {
                pre[a] = suf[a] = c;
                dp[a] = 0;
                for(int j = 4; j <= c.size(); ++j) {
                    if(c.substr(j - 4, 4) == "haha") {
                        dp[a]++;
                    }
                }
            }
            last = a;
        }
        cout << dp[last] << endl;
    }
}