#include <bits/stdc++.h>
//#define int long long

using namespace std;

void relax(map <int, int> &m, int c, int val) {
    if (m.find(c) == m.end()) 
        m[c] = val;
    m[c] = max(m[c], val);
}

void select_best(map <int, int> &m) {
    vector <pair <int, int>> vals;
    for (auto elem : m) {
        vals.push_back({elem.second, elem.first});
    }
    sort(vals.begin(), vals.end(), greater <pair <int, int>>());
    m.clear();
    for (int i = 0; i < min((int) vals.size(), 10); i++)
        m[vals[i].second] = vals[i].first;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    map <int, int> dp, dp2;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp2.clear();
        int add = (a[i] != a[i - 1]);
        for (auto elem : dp)
            relax(dp2, elem.first, elem.second + add);
        for (auto elem : dp)
            relax(dp2, a[i - 1], elem.second + (elem.first != a[i]));
        select_best(dp2);
        dp = dp2;
    }
    int res = 0;
    for (auto elem : dp)
        res = max(res, elem.second);
    cout << res << endl;
    return 0;
}