#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
int a[maxn], b[maxn];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    vector<int> o(n); iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](const int &i, const int &j) { return make_pair(b[i], a[i]) > make_pair(b[j], a[j]); });
    int now = 1, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (now == 0) break;
        --now;
        now += b[o[i]]; ans += a[o[i]];
    }
    cout << ans << endl;
}