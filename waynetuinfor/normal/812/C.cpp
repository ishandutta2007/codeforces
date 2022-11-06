#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], n, s, last;
vector<pair<int, int>> vec;
typedef long long ll;

bool check(int);

main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> s;
    // vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i) cin >> a[i], vec.push_back(make_pair(a[i], i + 1));
    
    // sort(a, a + n);
    int d = 1, ans = 0; while (d <= n) d <<= 1;
    while (d >>= 1) if (ans + d <= n) if (check(ans + d)) ans += d;
    cout << ans << ' ' << last << endl;
    return 0;
}

bool check(int t) {
    int tot = 0;
    sort(vec.begin(), vec.end(), [=](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first + (ll)a.second * (ll)t < b.first + (ll)b.second * (ll)t;
    });
    for (int i = 0; i < t; ++i) {
        tot += vec[i].first + (long long)vec[i].second * (long long)t;
    }
    if (tot <= s) last = tot;
    return tot <= s;
}