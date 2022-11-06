#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
pair<int, int> p[maxn];
int s[maxn], jizz[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, q; cin >> n >> k >> q;
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i) vec.push_back(make_pair(p[i].first, 1)), vec.push_back(make_pair(p[i].second + 1, -1));
    sort(vec.begin(), vec.end());
    int cur = 0, ind = 1;
    for (auto a : vec) {
        // cout << a.first << ' ' << a.second << ' ' << ind << endl;
        while (ind < a.first) {
            if (cur >= k) jizz[ind] = true;
            ++ind;
        }
        cur += a.second;
        // if (cur >= k) s[ind] = s[ind - 1] + 1;
    }
    for (int i = 1; i < maxn; ++i) s[i] = s[i - 1] + jizz[i];
    while (q--) {
        int a, b; cin >> a >> b;
        cout << s[b] - s[a - 1] << endl;
    }
    return 0;
}