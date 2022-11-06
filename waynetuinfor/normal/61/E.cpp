#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6 + 10;

struct Fenwick {
    int arr[maxn];
    void init() {
        memset(arr, 0, sizeof(arr));
    }
    inline int lowbit(int x) {
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
} bit1, bit2;

int a[maxn];

void add(int ind) {
    int bg = bit2.qry(maxn - 1) - bit2.qry(ind);
    bit1.add(ind, bg); bit2.add(ind, 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) cin >> a[i], v.emplace_back(a[i]);
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    bit1.init(), bit2.init();
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int ind = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        ans += bit1.qry(maxn - 1) - bit1.qry(ind);
        add(ind);
    }
    cout << ans << endl;
    return 0;
}