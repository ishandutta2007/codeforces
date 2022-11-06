#include <bits/stdc++.h>
using namespace std;

const int maxn = 24, inf = 1e9;
int dp[1 << maxn], n;
pair<int, int> p[maxn], pos, t[1 << maxn];

int dist(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int go(int s) {
    // cout << "s = " << s << endl;
    if (s == 0) return 0;
    if (dp[s]) return dp[s];
    dp[s] = inf;
    for (int i = 0; i < n; ++i) if (s & (1 << i)) {
        int tdp = go(s ^ (1 << i)) + dist(pos, p[i]) * 2;
        if (tdp < dp[s]) dp[s] = tdp, t[s] = make_pair(i, i);
        break;
    }
    for (int i = 0; i < n; ++i) if (s & (1 << i)) {
        for (int j = 0; j < n; ++j) if (i != j) {
            if (s & (1 << j)) {
                int tdp = go(s ^ (1 << i) ^ (1 << j)) + dist(pos, p[i]) + dist(p[i], p[j]) + dist(p[j], pos);
                if (tdp < dp[s]) dp[s] = tdp, t[s] = make_pair(i, j);
            }
        }
        return dp[s];
    }
}

int main() {
    cin >> pos.first >> pos.second;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second; 
    int ans = go((1 << n) - 1);
    cout << ans << endl;
    int s = ((1 << n) - 1);
    vector<int> tour; tour.push_back(0);
    while (s) {
        int a = t[s].first, b = t[s].second;
        if (a != b) {
            tour.push_back(a + 1); 
            tour.push_back(b + 1);
            s ^= (1 << a) | (1 << b);
        } else {
            tour.push_back(a + 1);
            s ^= (1 << a);
        }
        tour.push_back(0);
    }
    for (int i : tour) cout << i << ' '; cout << endl;
    return 0;
}