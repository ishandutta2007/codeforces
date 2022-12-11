#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 7;

int solve(vector <vector <int>> a) {
    vector <pair <int, int>> cnt(N, {0, 0});
    int n = a.size(), m = a[0].size();
    int sm = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cl = a[i][j];
            sm += i * cnt[cl].first - cnt[cl].second;
            cnt[cl].first++;
            cnt[cl].second += i;
        }
    }
    return sm;
}


signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector<int>(m, 0));
    vector <vector <int>> a_t(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a_t[j][i] = a[i][j];
        }
    }
    cout << solve(a) + solve(a_t) << "\n";
    return 0;
}