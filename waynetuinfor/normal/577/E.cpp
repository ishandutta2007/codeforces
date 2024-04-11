#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int x[maxn], y[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int mxc = 0;
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i], mxc = max(mxc, max(x[i], y[i]));
    int sz = 1 + (int)sqrt(mxc);
    for (int i = 0; i < n; ++i) x[i] /= sz, y[i] *= (x[i] & 1 ? 1 : -1);
    vector<int> ord(n); iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](const int &i, const int &j) { return x[i] == x[j] ? y[i] < y[j] : x[i] < x[j]; });
    for (int i = 0; i < n; ++i) cout << ord[i] + 1 << ' '; cout << endl;
    return 0;
}