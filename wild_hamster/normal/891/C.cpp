#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <time.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
typedef int ll;
using namespace std;

ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll p[500500], trash[500500], merged_cnt[500500], used[500500], w[500500], glob, cnt;
pii color[500500];
vector<pair<pii,int>> f[500500];
vector<pii> shit;
vector<ll> g[500500];
bool flag;
int dsu_get (int v) {
    return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {
    a = dsu_get (a);
    b = dsu_get (b);
    if (rand() & 1)
        swap (a, b);
    if (a != b)
        p[a] = b;
}
void dfs(ll x, ll pp = -1) {
    if (used[x] == glob) {
        flag = false;
        return;
    }
    used[x] = glob;
    for (int i = 0; i < g[x].size(); i++)
        if (g[x][i] != pp)
            dfs(g[x][i], x);
}
int main() {
    //freopen("input.txt","r",stdin);
    srand(time(0));
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d",&x,&y,&z);
        f[z].push_back(mp(mp(x,y), i+1));
        w[i+1] = z;
    }
    for (int i = 1; i <= 500000; i++) {
        for (int j = 0; j < f[i].size(); j++) {
            int x = dsu_get(f[i][j].X.X);
            int y = dsu_get(f[i][j].X.Y);
            if (x == y)
                trash[f[i][j].Y] = 1;
            else
                color[f[i][j].Y] = mp(min(x,y), max(x,y));
        }
        for (int j = 0; j < f[i].size(); j++) {
            int x = dsu_get(f[i][j].X.X);
            int y = dsu_get(f[i][j].X.Y);
            if (x != y) {
                dsu_unite(x, y);
                merged_cnt[i]++;
            }
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        scanf("%d",&k);
        flag = true;
        shit.clear();
        for (int j = 0; j < k; j++) {
            scanf("%d",&x);
            //cout << x << " " << trash[x] << " " << color[x].X << " " << color[x].Y << endl;
            if (trash[x])
                flag = false;
            else {
                shit.push_back(mp(w[x],color[x].X));
                shit.push_back(mp(w[x],color[x].Y));
                g[color[x].Y].push_back(color[x].X);
                g[color[x].X].push_back(color[x].Y);
            }

        }
        sort(shit.begin(), shit.end());
        glob = i+1;
        cnt = 0;
        int total = 0;
        int hyu = 0;
        for (int j = 0; j < shit.size(); j++) {
            if (used[shit[j].Y] == glob)
                continue;
            dfs(shit[j].Y);
        }
        if (flag == false)
            printf("NO\n");
        else
            printf("YES\n");
        for (int j = 0; j < shit.size(); j++) {
            g[shit[j].Y].clear();
        }
    }
    return 0;
}