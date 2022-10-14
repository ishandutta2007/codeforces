// Words are flowing out like endless rain into a paper cup
// They slither while they pass they slip away across the universe
// Pools of sorrow, waves of joy are drifting through my open mind
// Possessing and caressing me
 
#include <bits/stdc++.h>
using namespace std;
 
using LL = long long;
 
namespace _buff {
 
const size_t BUFF = 1 << 19;
char ibuf[BUFF], *ib = ibuf, *ie = ibuf;
char getc() {
    if (ib == ie) {
        ib = ibuf;
        ie = ibuf + fread(ibuf, 1, BUFF, stdin);
    }
    return ib == ie ? -1 : *ib++;
}
 
}
 
LL read() {
    using namespace _buff;
    LL ret = 0;
    bool pos = true;
    char c = getc();
    for (; (c < '0' || c > '9') && c != '-'; c = getc()) {
        assert(~c);
    }
    if (c == '-') {
        pos = false;
        c = getc();
    }
    for (; c >= '0' && c <= '9'; c = getc()) {
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
    }
    return pos ? ret : -ret;
}
 
const size_t N = 7;
 
int n, col[N], ans;
bool edge[N][N], vis[6][6];
 
void solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (edge[i][j]) {
                vis[col[i]][col[j]] = true;
            }
        }
    }
    int cur = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = i; j < 6; ++j) {
            cur += vis[i][j];
            vis[i][j] = false;
        }
    }
    ans = max(ans, cur);
}
 
void dfs(int i) {
    if (i == n) {
        return solve();
    }
    for (int &j = col[i] = 0; j < 6; ++j) {
        dfs(i + 1);
    }
}
 
int main() {
    n = read();
    int m = read();
    while (m--) {
        int x = read() - 1, y = read() - 1;
        edge[x][y] = edge[y][x] = true;
    }
    dfs(0);
    cout << ans << '\n';
    return 0;
}