#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    int sq = 200;
    vector<int> c(m + 1), pre(n, -1);
    vector<vector<int>> d(sq + 1, vector<int>(sq + 1));
    for(int t = 0; t < m; ++t) {
        int op, k;
        cin >> op >> k;
        --k;
        if(op == 1) {
            if((a[k] + b[k]) >= sq) {
                for(int j = t; j <= m; j += a[k] + b[k]) {
                    if(j + a[k] <= m) c[j + a[k]] += 1;
                    if(j + a[k] + b[k] <= m) c[j + a[k] + b[k]] -= 1;
                }
                pre[k] = t;
            } else {
                // mod = a[k] + b[k], start = t + a[k]
                for(int i = t + a[k]; i < t + a[k] + b[k]; ++i) {
                    d[a[k] + b[k]][i % (a[k] + b[k])] += 1;
                }
                pre[k] = t + a[k];
            }
        } else {
            if((a[k] + b[k]) >= sq) {
                assert(pre[k] != -1);
                for(int j = pre[k]; j <= m; j += a[k] + b[k]) {
                    if(j + a[k] <= m) c[max(t, j + a[k])] -= 1;
                    if(j + a[k] + b[k] <= m) c[max(t, j + a[k] + b[k])] += 1;
                }
                pre[k] = -1;
            } else {
                assert(pre[k] != -1);
                for(int i = pre[k]; i < pre[k] + b[k]; ++i) {
                    d[a[k] + b[k]][i % (a[k] + b[k])] -= 1;
                }
                pre[k] = -1;
            }
        }
        c[t + 1] += c[t];
        int ans = c[t];
        assert(c[t] >= 0);
        for(int i = 1; i < sq; ++i) {
            ans += d[i][t % i];
        }
        cout << ans << '\n';
    }
}