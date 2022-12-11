#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;
const int MOD = 998244353;
int n, a[N][N];
long long dera[N], pderan[N];
long long f[N][N];

struct {
    int a[N];
    void clear() {
        memset(a, 0, sizeof(a));
    }
    void add(int x, int v) {
        assert(x != 0);
        while (x <= n) {
            a[x] += v;
            x += x & -x;
        }
    }
    int get(int x) {
        int ans = 0;
        while (x) {
            ans += a[x];
            x -= x & -x;
        }
        return ans;
    }
}mbit[2];
void prepare() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    dera[0] = 1;
    for(int i = 2; i < N; i++)
        dera[i] = (i - 1) * (dera[i - 1] + dera[i - 2]) % MOD;

    pderan[0] = 1;
    for(int i = 1; i <= n; i++)
        pderan[i] = pderan[i - 1] * dera[n] % MOD;
    
    f[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        f[i][0] = f[i - 1][0] * i % MOD;
        for(int j = 1; j <= i; j++) {
            f[i][j] = (f[i][j - 1] - f[i - 1][j - 1] + MOD) % MOD;
        }
    }
}
int solve() {
    long long ans = 0;
    int app[2][N];
    for(int row = 1; row <= n; row++) {
        for(int i = 0; i <= 1; i++) {
            mbit[i].clear();
            fill(app[i] + 1, app[i] + n + 1, (row - i >= 1));
            for(int j = 1; j <= n; j++) mbit[i].add(j, app[i][j]);
        }
        long long sans = 0;
        for(int col = 1; col <= n; col++) {
            int stuck = (a[row - 1][col] < a[row][col] && app[0][a[row - 1][col]]);
            int avail = mbit[0].get(a[row][col] - 1) - stuck;
            int bad = mbit[1].get(a[row][col] - 1) - stuck;
            int rot = mbit[1].get(n) - app[0][a[row - 1][col]];
            //cout << col << " " << avail << " " << bad << " " << rot << '\n';
            sans = (sans + (avail - bad) * f[n - col][rot] + bad * f[n - col][rot - 1]) % MOD;
            mbit[0].add(a[row][col], -1);
            for(int j = 0; j <= 1; j++) {
                if (app[0][a[row - j][col]] && app[1][a[row - j][col]]) 
                    mbit[1].add(a[row - j][col], -1);
                app[j][a[row - j][col]]--;
            }
        }
        ans = (ans + sans * pderan[n - row]) % MOD;
        //cout << ans << '\n';
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prepare();
    cout << solve();
}