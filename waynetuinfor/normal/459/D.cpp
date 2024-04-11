#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn], cnt[maxn], tot[maxn];

struct Fenwick {
    int arr[maxn];
    void init() {
        memset(arr, 0, sizeof(arr));
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) arr[i] += v;
    }
    int qry(int x) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret += arr[i];
        return ret;
    }
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; ++i) cin >> a[i], v.push_back(a[i]);
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; ++i) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    for (int i = 1; i <= n; ++i) ++cnt[a[i]], ++tot[a[i]];
    long long ans = 0;
    for (int i = n; i >= 1; --i) {
        ans += bit.qry(cnt[a[i]] - 1);
        --cnt[a[i]];
        if (tot[a[i]] - cnt[a[i]]) bit.add(tot[a[i]] - cnt[a[i]], 1);
    }
    cout << ans << endl;
    return 0;
}