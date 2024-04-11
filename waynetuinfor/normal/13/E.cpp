#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, sq = 500;
int a[maxn], bid[maxn], lb[maxn / sq + 10], rb[maxn / sq + 10];
int to[maxn], cnt[maxn], des[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int block = 0;
    for (int i = 1; i <= n; ) {
        int j = 0; ++block;
        lb[block] = i;
        while (j < sq && i + j <= n) {
            bid[i + j] = block;
            ++j;
        }
        rb[block] = i + j - 1;
        i += j;
    }
    for (int b = block; b >= 1; --b) {
        for (int i = rb[b]; i >= lb[b]; --i) {
            if (i + a[i] > rb[b]) {
                to[i] = i + a[i];
                if (i + a[i] > n) des[i] = i;
                else des[i] = des[to[i]];
                cnt[i] = 1;
            } else {
                to[i] = to[i + a[i]];
                cnt[i] = cnt[i + a[i]] + 1;
                des[i] = des[i + a[i]];
            }
            assert(to[i] > rb[bid[i]]);
        } 
    }
    while (m--) {
        int t; cin >> t;
        if (t == 0) {
            int p, v; cin >> p >> v;
            assert(v > 0);
            a[p] = v;
            for (int i = rb[bid[p]]; i >= lb[bid[p]]; --i) {
                if (i + a[i] > rb[bid[p]]) {
                    to[i] = i + a[i];
                    if (i + a[i] > n) des[i] = i;
                    else des[i] = des[i + a[i]];
                    cnt[i] = 1;
                } else {
                    to[i] = to[i + a[i]];
                    assert(to[i] > rb[bid[p]]);
                    cnt[i] = 1 + cnt[i + a[i]];
                    des[i] = des[i + a[i]];
                }
            }
        } else {
            int p; cin >> p;
            int ans = 0, pos = -1;
            while (p <= n) {
                pos = des[p]; 
                ans += cnt[p];
                p = to[p];
            }
            cout << pos << ' ' << ans << endl;
        }
    }
    return 0;
}