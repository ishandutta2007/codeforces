#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define pii pair<int, int>
#define fr first
#define se second
const int mod = 998244353, MAXN = 1010;
char a[MAXN]; int n, fr;
int vis[MAXN][2];

bool res;

vector <pii> vec;
void dfs (int x, int y, int now) {
    if (y && x < fr) return;
    if (vis[x][y] != -1) {
        if (vis[x][y] != now) { res = 0; }
        return;
    }
    vis[x][y] = now; vec.push_back(make_pair(x, y));
    if (a[x] != '?') dfs(x, y ^ 1, now ^ (a[x] - '0'));
    if (y == 0) dfs(n - x + 1, y, now); else dfs(n + fr - x, y, now);
}

int main () {
    scanf("%s", a + 1); n = strlen(a + 1); int i, j, ans = 0;
    for (fr = 2; fr <= n; fr++) {
        int tmp = 1; res = 1;
        for (i = 1; i <= n; i++) vis[i][0] = vis[i][1] = -1;
        for (int x = 1; x <= n; x++) for (int y = 0; y <= 1; y++) if ((x >= fr || y == 0) && vis[x][y] == -1) {
            vec.clear();
            dfs(x, y, 0); bool judge[2] = {}, havpre = 0;
            for (auto i: vec) {
                havpre |= (i.fr == fr) && i.se;
                if (!i.se && i.fr < fr && a[i.fr] != '?') judge[vis[i.fr][i.se] == a[i.fr] - '0'] = 1;
            }
            if (judge[0] && judge[1]) res = 0;
            else if (havpre) {
                if ((judge[0] || judge[1]) && !judge[vis[fr][1]]) res = 0;
            }
            else tmp = (tmp << (!judge[0] && !judge[1])) % mod;
        }
        if (res) ans = (ans + tmp) % mod;
    }
    printf("%d\n", (ans + mod) % mod);
    return 0;
}