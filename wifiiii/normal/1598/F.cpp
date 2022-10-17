#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<string> a(n);
    vector<int> cnt(n);
    vector<map<int,int>> mp(n);
    vector<vector<int>> mn(n);
    vector<vector<vector<int>>> qwq(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[i] = count(a[i].begin(), a[i].end(), '(');
        mn[i].resize(a[i].size() + 1);
        mn[i][0] = 1e9;
        int cur = 0;
        qwq[i].resize(a[i].size() * 2 + 1);
        for(int j = 0; j < a[i].size(); ++j) {
            if(a[i][j] == '(') cur += 1;
            else cur -= 1;
            mn[i][j + 1] = min(mn[i][j], cur);
            qwq[i][cur + a[i].size()].push_back(j);
        }
    }
    vector<int> sum1(1 << n), sum0(1 << n);
    for(int i = 1; i < 1 << n; ++i) {
        for(int j = 0; j < n; ++j)
            if(i >> j & 1) sum1[i] += cnt[j], sum0[i] += a[j].size() - cnt[j];
    }
    vector<int> dp(1 << n, -1e9);
    int ans = 0;
    dp[0] = 0;
    for(int i = 1; i < 1 << n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i >> j & 1) {
                if(dp[i ^ (1 << j)] == -1e9) continue;
                int pre = sum1[i ^ (1 << j)] - sum0[i ^ (1 << j)];
                assert(pre >= 0);
                int lo = 0, hi = a[j].size();
                while(lo < hi) {
                    int mid = (lo + hi + 1) / 2;
                    if(pre + mn[j][mid] < 0) hi = mid - 1;
                    else lo = mid;
                }
                int tmp = 0;
                if(-pre+a[j].size()>=0 && -pre+a[j].size()<=2*a[j].size()) {
                    tmp += lower_bound(qwq[j][-pre+a[j].size()].begin(), qwq[j][-pre+a[j].size()].end(), lo) - qwq[j][-pre+a[j].size()].begin();
                }
                ans = max(ans, dp[i ^ (1 << j)] + tmp);
                if(pre + mn[j][a[j].size()] >= 0) {
                    dp[i] = max(dp[i], dp[i ^ (1 << j)] + tmp);
                }
            }
        }
    }
    cout << ans << '\n';
}