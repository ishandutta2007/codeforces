#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, sq = 2300;
int a[maxn], lb[maxn], rb[maxn], bid[maxn];

struct fenwick {
    int data[maxn];
    void init() { memset(data, 0, sizeof(data)); }
    void add(int x, int v) { for (; x < maxn; x += x & -x) data[x] += v; }
    int qry(int x, int ret = 0) { for (; x; x -= x & -x) ret += data[x]; return ret; }
} bit[maxn / sq + 5];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    int block = 0;
    for (int i = 1; i <= n; ) {
        ++block;
        int j = 0;
        while (j < sq && i + j <= n) {
            bid[i + j] = block;
            lb[i + j] = i;
            ++j;
        }
        for (int k = 0; k < j; ++k) rb[i + k] = i + j - 1;
        i += j;
    }
    for (int i = 1; i <= n; ++i) {
        bit[bid[i]].add(i, 1);
        a[i] = i;
    }
    long long ans = 0;
    while (q--) {
        int l, r; cin >> l >> r;
        if (l > r) swap(l, r);
        if (l == r) {
            cout << ans << '\n';
            continue;
        }
        if (bid[l] == bid[r]) {
            long long c1 = 0, c2 = 0;
            for (int i = l + 1; i < r; ++i) {
                if (a[i] < a[r]) ++c1;
                if (a[i] > a[r]) --c1;
                if (a[i] > a[l]) ++c2;
                if (a[i] < a[l]) --c2;
            }
            ans += c1 + c2;
            if (a[l] > a[r]) --ans;
            else ++ans;
            swap(a[l], a[r]);
            cout << ans << '\n';
            continue;
        }
        long long c1 = 0, c2 = 0;
        for (int b = bid[l] + 1; b < bid[r]; ++b) {
            c1 += bit[b].qry(a[r]);
            c1 -= bit[b].qry(maxn - 1) - bit[b].qry(a[r]);
            c2 += bit[b].qry(maxn - 1) - bit[b].qry(a[l]);
            c2 -= bit[b].qry(a[l]);
        }
        bit[bid[r]].add(a[r], -1); bit[bid[l]].add(a[l], -1);
        for (int i = l + 1; i <= rb[l]; ++i) {
            if (a[i] < a[r]) ++c1;
            if (a[i] > a[r]) --c1;
            if (a[i] > a[l]) ++c2;
            if (a[i] < a[l]) --c2;
        }
        for (int i = lb[r]; i < r; ++i) {
            if (a[i] < a[r]) ++c1;
            if (a[i] > a[r]) --c1;
            if (a[i] > a[l]) ++c2;
            if (a[i] < a[l]) --c2;
        }
        ans += c1 + c2;
        bit[bid[r]].add(a[l], 1); bit[bid[l]].add(a[r], 1);
        if (a[l] > a[r]) --ans;
        else ++ans;
        swap(a[l], a[r]);
        cout << ans << '\n';
    }
    return 0;
}