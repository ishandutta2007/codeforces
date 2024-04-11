#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,z,q,timer, v,x,y,xx, yy,INF, sz,n,m, cnt, even, odd;
long long ans = 0, cur = 0;
ll w[200500];
vector<int> g[200500];
void dfs(int v, int lvl, int p = -1) {
    if (lvl % 2 == 0)
        even++;
    else
        odd++;
    cur += lvl;
    w[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != p) {
            dfs(to, lvl+1, v);
            w[v] += w[to];
        }
    }
}

void dfs2(int v, long long cur, int even, int odd, int p = -1) {
    //cout << v << " " << cur << " " << even << " " << odd << endl;
    ans += (cur+odd)/2;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != p) {
            dfs2(to, cur + n - 2*w[to], odd, even, v);
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    //cout << cur << " " << even << " " << odd << endl;
    dfs2(1, cur, even, odd);
    cout << ans/2 << endl;
    return 0;
}