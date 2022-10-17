#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
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

const int MAXN = 303;
int n, m, a[MAXN * MAXN], b[MAXN * MAXN];
int vis[MAXN][MAXN];

map <int, int> lsh;
vector <int> v[MAXN * MAXN];

int main () {
    int T = read();
    while (T--) {
        n = read(), m = read(); int i,j ;
        for (i = 0; i < n * m; i++) a[i] = b[i] = read();
        for (i = 0; i < n; i++) for (j = 0; j < m; j++) vis[i][j] = -1;
        sort(b, b + n * m); int top = 0; lsh.clear();
        for (i = 0; i < n * m; i++) {
            if (!lsh.count(b[i])) lsh[b[i]] = ++top;
            v[lsh[b[i]]].push_back(i); // printf("push %d to %d\n", i, lsh[b[i]]);
        }
        for (i = 1; i <= top; i++) reverse(v[i].begin(), v[i].end());
        // puts("rua");
        long long ans = 0;
        for (i = 0; i < n * m; i++) {
            int now = a[i];
            int pos = v[lsh[now]].back(); v[lsh[now]].pop_back();
            // cout << now << ' ' << pos << endl;
            int x = pos / m, y = pos % m; vis[x][y] = now;
            for (j = 0; j < y; j++) if (vis[x][j] != -1 && vis[x][j] != now) ++ans; //, printf("!! %d %d\n", j, vis[x][j]);
        }
        cout << ans << endl;
        for (i = 1; i <= top; i++) v[i].clear();
    }
    return 0;
}