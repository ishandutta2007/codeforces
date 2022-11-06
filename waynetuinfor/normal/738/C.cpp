#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
pair<int, int> p[maxn];
int g[maxn], n, k, s, t;

bool check(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> s >> t;
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
    for (int i = 0; i < k; ++i) cin >> g[i];
    sort(g, g + k); g[k] = s;
    int d = 1, ans = (int)1e9;
    while (d <= (int)1e9) d <<= 1;
    while (d >>= 1) if (ans - d > 0) if (check(ans - d)) ans -= d;
    if (!check(ans)) return cout << "-1\n", 0;
    cerr << "ans: " << ans << '\n';
    sort(p, p + n, [=](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    int it = lower_bound(p, p + n, make_pair(-1, ans), [=](const pair<int, int>& a, const pair<int, int>&b) {
        return a.second < b.second;
    }) - p;
    if (p[it].second < ans) return cout << "-1\n", 0;
    cerr << "it: " << it << '\n';
    sort(p + it, p + n, [=](const pair<int, int>& a, const pair<int, int>& b){
        return a.first < b.first;
    });
    return cout << p[it].first << '\n', 0;
}

bool check(int v) {
    int tm = 0;
    int pos = 0;
    for (int i = 0; i <= k; ++i) {
        int dis = g[i] - pos;
        int x = min(v - dis, dis);
        if (x < 0) return false;
        tm += 2 * (dis - x) + x;
        pos = g[i];
    }
    return tm <= t;
}