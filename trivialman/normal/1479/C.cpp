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

int T, l, r, n, s;
vector<ar2> g[N];

void solve(int x) {
    if (x <= 4) {
        if (x == 1)
            g[s].PB({n + 1, 1}), n++;
        else if (x == 2)
            g[s].PB({n + 1, 1}), g[n + 1].PB({n + 2, 1}), g[s].PB({n + 2, 1}), n += 2;
        else if (x == 3)
            g[s].PB({n + 1, 1}), g[n + 1].PB({n + 2, 1}), g[n + 2].PB({n + 3, 1}), g[n + 1].PB({n + 3, 1}), g[s].PB({n + 3, 1}), n += 3;
        else
            g[s].PB({n + 1, 1}), g[n + 1].PB({n + 2, 1}), g[n + 2].PB({n + 3, 1}),
                g[n + 1].PB({n + 3, 1}), g[s].PB({n + 3, 1}), g[s].PB({n + 2, 3}), n += 3;
        return;
    }
    int m = (x - 1) / 4;
    solve(m);
    switch (x % 4) {
    case 1: {
        g[s].PB({n + 3, 1}), g[n].PB({n + 1, m}), g[n + 1].PB({n + 2, m}), g[n].PB({n + 2, m * 3}),
            g[n].PB({n + 3, 1}), g[n + 1].PB({n + 3, 1}), g[n + 2].PB({n + 3, 1}), n += 3;
        break;
    }
    case 2: {
        g[s].PB({n + 3, 1}), g[n].PB({n + 1, m}), g[n + 1].PB({n + 2, m}), g[n].PB({n + 2, m * 3}),
            g[n].PB({n + 3, 1}), g[n + 1].PB({n + 3, 1}), g[n + 2].PB({n + 3, 1}),
            g[s].PB({n + 2, 4 * m + 1}), n += 3;
        break;
    }
    case 3: {
        g[s].PB({n + 3, 1}), g[n].PB({n + 1, m}), g[n + 1].PB({n + 2, m + 1}), g[n].PB({n + 2, m * 3 + 2}),
            g[n].PB({n + 3, 1}), g[n + 1].PB({n + 3, 1}), g[n + 2].PB({n + 3, 1}),
            g[s].PB({n + 1, 2 * m + 1}), n += 3;
        break;
    }
    case 0: { //4m+4
        g[s].PB({n + 3, 1}), g[n].PB({n + 1, m}), g[n + 1].PB({n + 2, m + 1}), g[n].PB({n + 2, m * 3 + 2}),
            g[n].PB({n + 3, 1}), g[n + 1].PB({n + 3, 1}), g[n + 2].PB({n + 3, 1}),
            g[s].PB({n + 1, 2 * m + 1}), g[s].PB({n + 2, 4 * m + 3}), n += 3;
    }
    }
    cerr << x << " " << n << endl;
}

int main() {
    cin >> l >> r;
    s = 1;
    if (l > 1)
        g[1].PB({2, l - 1}), s = 2, r -= l - 1, l = 1;

    n = s;
    solve(r);

    cout << "YES\n";
    int m = 0;
    rep(i, 1, n) m += g[i].size();
    cout << n << " " << m << endl;
    rep(i, 1, n) for (auto ele : g[i])
            cout
        << i << " " << ele[0] << " " << ele[1] << endl;
    return 0;
}