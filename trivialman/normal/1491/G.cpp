#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const int N = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, numcyc = 0;
int a[N];
bool v[N];
vector<int> cyc[N];
vector<ar2> ans;

void reorder_1(const vector<int> &c) {
    int sz = c.size();
    if (sz == 2) {
        //need outer number
        int idx, x = c[0], y = c[1];
        rep(i, 1, n) if (i != x && i != y) idx = i;
        ans.PB({x, idx}), ans.PB({y, idx}), ans.PB({x, idx});
    } else {
        //doesn't need outer number
        ans.PB({c[0], c[sz - 1]}), ans.PB({c[0], c[sz - 2]});
        rep(i, 1, sz - 2) ans.PB({c[i], c[sz - 1]});
        ans.PB({c[0], c[sz - 1]});
    }
}

void reorder_2(const vector<int> &c, const vector<int> &d) {
    int sz1 = c.size(), sz2 = d.size();
    ans.PB({c[sz1 - 1], d[sz2 - 1]});
    rep(i, 0, sz1 - 2) ans.PB({c[i], d[sz2 - 1]});
    rep(i, 0, sz2 - 2) ans.PB({d[i], c[sz1 - 1]});
    ans.PB({c[sz1 - 1], d[sz2 - 1]});
}

int main() {
    cin >> n;
    rep(i, 1, n) scanf("%d", a + i);
    memset(v, 0, sizeof v);
    rep(i, 1, n) if (a[i] != i && !v[i]) {
        v[i] = true;
        int j = a[i];
        ++numcyc, cyc[numcyc].PB(j);
        while (!v[j])
            v[j] = true, j = a[j], cyc[numcyc].PB(j);
    }

    for (int i = 1; i < numcyc; i += 2)
        reorder_2(cyc[i], cyc[i + 1]);
    if (numcyc % 2)
        reorder_1(cyc[numcyc]);

    cout << ans.size() << endl;
    for (ar2 x : ans)
        printf("%d %d\n", x[0], x[1]);
    return 0;
}