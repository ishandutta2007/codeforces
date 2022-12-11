#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
const int MOD = 998244353;

int n;
vector<int> v[N];

int pa[N];
int q[N];


long long f[N][2], g[N];
void BFS() {
    int top = 1, bot = 1;
    q[1] = 1;
    while (top <= bot) {
        int x = q[top++];
        for(auto y : v[x]) if (y != pa[x]) {
            pa[y] = x;
            q[++bot] = y;
        }
    }
}
void prepare() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    BFS();
}
template <class T>
inline void add(T &x, long long y) {
    x = (x + y) % MOD;
}
void calg(int x) {
    g[x] = 1;
    for(auto y : v[x]) if (y != pa[x]) 
        g[x] = g[x] * g[y] % MOD;
    long long tmpg[2][2];
    memset(tmpg, 0, sizeof(tmpg));
    tmpg[0][0] = 1;
    for(auto y : v[x]) if (y != pa[x]) {
        for(int u1 = 0; u1 < 2; u1++) tmpg[1][u1] = tmpg[0][u1]; 
        memset(tmpg[0], 0, sizeof(tmpg[0]));
        add(tmpg[0][1], tmpg[1][0] * f[y][1] + tmpg[1][1] * (f[y][0] + g[y]));
        add(tmpg[0][0], tmpg[1][0] * (f[y][0] + g[y]));
    }
    add(g[x], tmpg[0][1]);
}
void calf(int x) {
    long long tmpg[2][2];
    memset(tmpg, 0, sizeof(tmpg));
    tmpg[0][0] = 1;
    for(auto y : v[x]) if (y != pa[x]) {
        for(int u1 = 0; u1 < 2; u1++) tmpg[1][u1] = tmpg[0][u1]; 
        memset(tmpg[0], 0, sizeof(tmpg[0]));
        add(tmpg[0][0], tmpg[1][0] * (g[y] + f[y][0]));
        add(tmpg[0][1], tmpg[1][1] * (g[y] + f[y][0]) + tmpg[1][0] * f[y][1]);
    }
    add(f[x][0], tmpg[0][1]);

    f[x][1] = 1;
    for(auto y : v[x]) if (y != pa[x]) {
        f[x][1] = (f[x][1] * (g[y] + f[y][0])) % MOD;
    }
}
int solve() {
    for(int phase = n; phase >= 1; phase--) {
        int x = q[phase];
        calg(x);
        calf(x);
        //cout << x << " " << f[x][0] << " " << f[x][1] << " " << g[x] << '\n';
    }
    return g[1];
}
int main() {
    prepare();
    cout << solve();
}