#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp(n, -1);
    vector<pair<int,int>> qwq;
    for(int i = 0; i < n; ++i) {
        vector<pair<int,int>> nxt;
        int pre = -1;
        for(auto [g, p] : qwq) {
            int ng = gcd(g, a[i]);
            if(ng != pre) nxt.push_back({ng, p});
            pre = ng;
        }
        if(pre != a[i]) nxt.push_back({a[i], i});
        qwq = nxt;
        for(int j = 0; j < nxt.size(); ++j) {
            int g = nxt[j].first, l = nxt[j].second, r = j + 1 < nxt.size() ? nxt[j + 1].second - 1 : i;
            if(l <= i - g + 1 && i - g + 1 <= r) {
                dp[i] = i - g + 1;
            }
        }
    }
    vector<int> ans(n, -1);
    int l = -1;
    for(int i = 0; i < n; ++i) {
        l = max(l, dp[i]);
        if(l == -1) ans[i] = 0;
        else ans[i] = (l ? ans[l - 1] : 0) + 1;
        cout << ans[i] << " ";
    }
    cout << '\n';
}