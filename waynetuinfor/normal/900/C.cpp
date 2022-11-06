#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], pos[maxn];
bool ok[maxn];

struct fenwick {
    int dat[maxn];
    void init() { memset(dat, 0, sizeof(dat)); }
    void add(int p, int v) { for (; p < maxn; p += p & -p) dat[p] += v; }
    int qry(int p, int v = 0) { for (; p; p -= p & -p) v += dat[p]; return v; }
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]] = i;
    bit.init();
    vector<int> vec;
    for (int i = 1; i <= n; ++i) {
        int fr = bit.qry(a[i]);
        int diff = i - 1 - fr;
        bit.add(a[i], 1);
        if (diff == 1) vec.push_back(i);
        else if (diff == 0) ok[i] = true;
    }
    bit.init();
    sort(vec.begin(), vec.end(), [&](const int &i, const int &j) { return a[i] < a[j]; });
    int bst = -1, now = -maxn;
    int p = 0;
    // for (int i : vec) cout << i << ' '; cout << endl;
    // for (int i = 1; i <= n; ++i) cout << ok[i] << ' '; cout << endl;
    for (int i = 1; i <= n; ++i) {
        while (p < vec.size() && a[vec[p]] < i) bit.add(vec[p], 1), ++p;
        int cur = (ok[pos[i]] ? -1 : 0);
        int bk = bit.qry(maxn) - bit.qry(pos[i]);
        // cout << "cur = " << cur << " bk = " << bk << endl;;
        if (cur + bk > now) now = cur + bk, bst = i;
    }
    cout << bst << endl;
    return 0;
}