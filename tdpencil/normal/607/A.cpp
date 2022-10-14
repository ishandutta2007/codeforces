#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5, M = 1e9+7;

void solve(int test_case = 0)
{
    cerr << "Case # " << test_case << ": ";
    int n; cin >> n;
    vector<pair<int, int>> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    
    vector<int> dp(n);
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            dp[i] = 1;
        } else {
            int l = a[i].second;
            int res = lower_bound(a.begin(), a.end(), pair<int, int>{a[i].first - a[i].second, 0}) - a.begin();
            if(a[res].first >= a[i].first - a[i].second) res--;
            
            if(res >= 0) dp[i] = 1 + dp[res];
            else dp[i] = 1;
        }
    }

    int ans = 0;
    int choice = n;
    for(int i = n - 1; i >= 0; i--) {
        if(dp[i] > ans) {
            ans = max(ans, dp[i]);
            choice = i;
        }
    }
    cout << n - ans << endl;

    
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
#ifdef runcase
    cin >> T;
#endif

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}