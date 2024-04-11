#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<ll,ll>
#define X first
#define Y second
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c,z;
vector<int> f, g[100500];
int d[100500];
void dfs(int v, int lvl, int p = -1) {
    if (p == -1) {
        if (g[v].size() < 3) {
            cout << "No" << endl;
            exit(0);
        }
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            dfs(to, lvl+1, v);
        }
        return;
    } else if (lvl == boom) {
        if (g[v].size() != 1) {
            cout << "No" << endl;
            exit(0);
        }
    } else {
        if (g[v].size() < 4) {
            cout << "No" << endl;
            exit(0);
        }
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (to != p)
                dfs(to, lvl+1, v);
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        d[i] = MOD;
    for (int i = 1; i <= n; i++)
    if (g[i].size() == 1) {
        f.push_back(i);
        d[i] = 0;
    }
    int i = 0;
    while (i < f.size()) {
        int v = f[i++];
        for (int j = 0; j < g[v].size(); j++) {
            int to = g[v][j];
            if (d[to] == MOD) {
                d[to] = d[v]+1;
                f.push_back(to);
            }
        }
    }
    int max1 = -1;
    int id = -1;
    for (int i = 1; i <= n; i++) {
        if (d[i] > max1)
            max1 = d[i];
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] == max1) {
            if (id != -1) {
                cout << "No" << endl;
                return 0;
            } else {
                id = i;
            }
        }
    }
    if (max1 != k) {
        cout << "No" << endl;
        return 0;
    }
    boom = k;
    dfs(id, 0);
    cout << "Yes" << endl;
    return 0;
}