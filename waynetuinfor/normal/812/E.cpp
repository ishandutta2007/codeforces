#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxv = 1e7 + 10;
int a[maxn], s, x[2][maxv << 1], col[maxn], l;
vector<int> T[maxn];

void dfs(int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        T[p].push_back(i);
        T[i].push_back(p);
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; ++i) {
        if (col[i] == l) s ^= a[i];
    }
    if (s == 0) {
        long long ans = 0, blue = 0, red = 0;
        for (int i = 1; i <= n; ++i) {
            if (col[i] == l) ans += x[l ^ 1][a[i]], ++blue;
            else ++red;
        }
        ans += (blue - 1) * blue / 2 + (red - 1) * red / 2;
        cout << ans << endl;
    } else {
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (col[i] == l) {
                int t = s ^ a[i];
                ans += x[l ^ 1][t];
            }
        }
        cout << ans << endl;
    }
}

void dfs(int cur, int fa, int c) {
    int ch = 0;
    ++x[c][a[cur]];
    col[cur] = c;
    for (int u : T[cur]) if (u != fa) {
        ++ch;
        dfs(u, cur, c ^ 1);
    }
    if (ch == 0) l = c;
}