#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int n, a[N], occ[N], nxt[N];

int main() {
    cin >> n;
    rep(i, 1, n) scanf("%d", a + i);
    rep(i, 1, n) occ[i] = n + 1;
    rrep(i, n, 1) nxt[i] = occ[a[i]], occ[a[i]] = i;
    nxt[0] = n + 1;

    vector<int> s, t;
    s.PB(0), t.PB(0);
    int ans = 0;
    rep(i, 1, n) {
        int x = s[s.size() - 1], y = t[t.size() - 1];
        if (a[i] == a[x])
            s.PB(i), ans += (a[i] != a[x]);
        else if (a[i] == a[y])
            t.PB(i), ans += (a[i] != a[y]);
        else
            (nxt[x] > nxt[y] ? s : t).PB(i), ans++;
    }
    cout << ans << endl;

    return 0;
}