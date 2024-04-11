#include <bits/stdc++.h>
using namespace std;

vector<int> a, lst, back;
vector<pair<int, int>> nxt;
int n, s, m, k;

int solve(int x) {
    vector<vector<int>> dp(s, vector<int>(m + 1));
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) {
        if(a[i - 1] <= x) ++p[i];
        p[i] += p[i - 1];
    }
    int ans = 0;
    for(int i = 0; i < s; i++) {
        for(int j = 0; j <= m; j++) {
            if(j == 0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = p[nxt[i].second] - p[nxt[i].first - 1];
            if(i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            if(lst[i] != -1) {
                dp[i][j] = max(dp[i][j], dp[lst[i]][j - 1] + p[nxt[i].second] - p[nxt[lst[i]].second]);
            }
            if(back[i] != -1) {
                dp[i][j] = max(dp[i][j], dp[back[i]][j - 1] + p[nxt[i].second] - p[nxt[i].first - 1]);
            }
        }
        ans = max(ans, dp[i][m]);
    }
    return ans;
}

int main() {
    cin >> n >> s >> m >> k;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> in(s);
    for(int i = 0; i < s; i++) {
        cin >> in[i].first >> in[i].second;
    }
    vector<bool> off(s);
    for(int i = 0; i < s; i++) {
        for(int j = 0; j < s; j++) {
            if(in[i].first == in[j].first && in[i].second == in[j].second) {
                if(j < i) off[i] = true;
            }
            else if(in[i].first >= in[j].first && in[i].second <= in[j].second) {
                off[i] = true;
            }
        }
    }
    for(int i = 0; i < s; i++) 
        if(!off[i])
            nxt.push_back(in[i]);
    sort(nxt.begin(), nxt.end());
    s = (int) nxt.size();
    lst.resize(s, -1), back.resize(s, -1);
    for(int i = 0; i < s; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(nxt[j].second >= nxt[i].first) {
                lst[i] = j;
            }
        }
        for(int j = i - 1; j >= 0; j--) {
            if(nxt[j].second < nxt[i].first) {
                back[i] = j;
                break;
            }
        }
    }
    
    int lo = 1, hi = 1000000001;
    int x = solve(1000000001);
    if(x < k) {
        cout << -1 << "\n";
        return 0;
    }
    for(int j = 0; j < 35; j++) {
        int mid = (lo + hi) / 2;
        x = solve(mid);
        if(x >= k)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << "\n";
}