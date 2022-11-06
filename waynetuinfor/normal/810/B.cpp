#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
pair<int, int> p[maxn];

int meow(const pair<int, int>& x) {
    int tmp = x.first * 2;
    // if (x.second <= tmp) return x.second;
    // if (x.second <= x.first * 2) return x.
    return min(x.second, tmp) - min(x.second, x.first);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, f; cin >> n >> f;
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
    sort(p, p + n, [](const pair<int, int>& a, const pair<int, int>& b) {
       return meow(a) > meow(b);
    });
    for (int i = 0; i < f; ++i) p[i].first *= 2;
    long long ans = 0;
    for (pair<int, int> t : p) ans += min(t.first, t.second);
    return cout << ans << endl, 0;
}