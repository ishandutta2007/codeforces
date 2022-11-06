#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, lg = 30;

struct fenwick {
    int data[maxn];
    void init() { memset(data, 0, sizeof(data)); }
    void add(int x, int v) { for (; x < maxn; x += x & -x) data[x] += v; }
    int qry(int x, int ret = 0) { for (; x; x -= x & -x) ret += data[x]; return ret; }
} bit;

int a[maxn], b[maxn], pos[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]] = i;
    for (int i = 1; i <= k; ++i) cin >> b[i], v[b[i]] = true;
    vector<int> vec;
    for (int i = 1; i <= n; ++i) vec.push_back(i);
    sort(vec.begin(), vec.end(), [&](const int &i, const int &j) { return a[i] < a[j]; });
    bit.init();
    for (int i = 1; i <= n; ++i) bit.add(i, 1);
    long long ans = 0;
    set<int> prv;
    prv.insert(0); prv.insert(n + 1);
    for (int p : vec) {
        if (v[a[p]]) {
            prv.insert(p);
            continue;
        } 
        int l = *(--prv.lower_bound(p));
        int r = *prv.upper_bound(p) - 1;
        ans += bit.qry(r) - bit.qry(l);
        bit.add(p, -1);
    }
    cout << ans << endl;
    return 0;
}