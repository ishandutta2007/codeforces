#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int N = 1010;
int p[N][N], sz[N][N];

int find(int id, int v) {
    return p[id][v] == v ? v : find(id, p[id][v]);
}

bool merge(int id, int a, int b) {
    a = find(id, a), b = find(id, b);
    if (a == b) {
        return false;
    }
    if (sz[id][a] < sz[id][b]) {
        swap(a, b);
    }
    p[id][b] = a;
    sz[id][a] += sz[id][b];
    return true;
}

int u[N], v[N], ans[N], add[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[0][i] = i;
        sz[0][i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            p[i][j] = p[i - 1][j];
            sz[i][j] = sz[i - 1][j];
        }
        cin >> u[i] >> v[i];
        add[i] = add[i - 1];
        if (!merge(i, u[i], v[i])) {
            add[i]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        vector<int> sizes;
        for (int j = 1; j <= n; j++) {
            if (find(i, j) == j) {
                sizes.push_back(sz[i][j]);
            }
        }
        sort(sizes.rbegin(), sizes.rend());
        for (int j = 0; j <= add[i]; j++) {
            ans[i] += sizes[j];
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] - 1 << '\n';
    }
}