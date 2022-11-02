#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int INF = 1e9;

int n, m;
vector<string> s;
vector< vector<int> > a, cost, msk;
vector<int> f;

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    s.resize(n);
    a.resize(n);
    cost.resize(n);
    msk.resize(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        a[i].resize(m);
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    for (int i = 0; i < n; i++) {
        cost[i].resize(m);
        msk[i].resize(m);
        for (int j = 0; j < m; j++) {
            cost[i][j] = 0;
            int mn = 0;
            msk[i][j] = 0;
            for (int k = 0; k < n; k++) {
                if (s[k][j] == s[i][j]) {
                    msk[i][j] += (1 << k);
                    cost[i][j] += a[k][j];
                    mn = max(mn, a[k][j]);
                }
            }
            cost[i][j] -= mn;
        }
    }
    f.resize(1<<n);
    for (int mask = 0; mask < (1 << n); mask++) f[mask] = INF;
    f[0] = 0;
    for (int mask = 0; mask + 1 < (1 << n); mask++) {
        if (f[mask] == INF) continue;
        int i = 0;
        while (mask & (1 << i)) ++i;
        for (int j = 0; j < m; j++) {
            f[mask+(1<<i)]=min(f[mask+(1<<i)],f[mask]+a[i][j]);
            f[mask|msk[i][j]]=min(f[mask|msk[i][j]],f[mask]+cost[i][j]);
        }
    }
    cout << f[(1<<n)-1] << endl;
}