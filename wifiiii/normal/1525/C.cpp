#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<tuple<int,char,int>> a(n);
        for(int i = 0; i < n; ++i) cin >> get<0>(a[i]);
        for(int i = 0; i < n; ++i) cin >> get<1>(a[i]);
        for(int i = 0; i < n; ++i) get<2>(a[i]) = i;
        sort(a.begin(), a.end());
        vector<int> ans(n, -1);
        vector<vector<pair<int,int>>> stk(2, vector<pair<int,int>>(n + 1));
        vector<int> tp(2);
        vector<vector<pair<int,int>>> stk2(2, vector<pair<int,int>>(n + 1));
        vector<int> tp2(2);
        for(auto [p, c, id] : a) {
            if(c == 'R') {
                stk[p & 1][++tp[p & 1]] = {p, id};
            } else {
                if(tp[p & 1]) {
                    auto [lp, li] = stk[p & 1][tp[p & 1]];
                    ans[li] = ans[id] = (p - lp) / 2;
                    --tp[p & 1];
                } else {
                    stk2[p & 1][++tp2[p & 1]] = {p, id};
                }
            }
        }
        for(int i = 0; i < 2; ++i) {
            while(tp[i] >= 2) {
                auto [p1, i1] = stk[i][tp[i]];
                auto [p2, i2] = stk[i][tp[i] - 1];
                tp[i] -= 2;
                ans[i1] = ans[i2] = m - p2 + (p2 - p1) / 2;
            }
            reverse(stk2[i].begin() + 1, stk2[i].begin() + tp2[i] + 1);
            while(tp2[i] >= 2) {
                auto [p1, i1] = stk2[i][tp2[i]];
                auto [p2, i2] = stk2[i][tp2[i] - 1];
                tp2[i] -= 2;
                ans[i1] = ans[i2] = p1 + (p2 - p1) / 2;
            }
            if(tp[i] && tp2[i]) {
                auto [p1, i1] = stk2[i][tp2[i]];
                auto [p2, i2] = stk[i][tp[i]];
                // p1 : L, p2 : R
                ans[i1] = ans[i2] = (p1 + m - p2 + m) / 2;
            }
        }
        for(int i = 0; i < n; ++i) cout << ans[i] << ' '; cout << '\n';
    }
}