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
#define INF 998244353
#define MAXN 1000005
typedef long long ll;
using namespace std;
ll i,j,k,q,x,y,n,m,  x1,y1,x2,y2,z;
struct pup {
    ll x, y, id;
} a[300500], b[300500];
ll pref[300500], ans[300500], suf[300500];
vector<ll> g[300500];
bool cmp(pup x, pup y) {
    return (x.y - x.x < y.y - y.x);
}
int main() {
    //freopen("input.txt", "r", stdin);
    //srand(time(0));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[i].x = x, a[i].y = y, a[i].id = i;
        b[i] = a[i];
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    sort(a, a+n, cmp);
    for (int i = 0; i< n; i++)
        pref[i+1] = pref[i] + a[i].y;
    for (int i = n-1; i >= 0; i--)
        suf[i] = suf[i+1] + a[i].x;

    for (int i = 0; i < n; i++) {
        ans[a[i].id] = pref[i] + suf[i+1] + a[i].x*i + a[i].y*(n-i-1);
        //cout << a[i].id << " " << ans[a[i].id] << endl;
        int to = a[i].id;
        for (int j = 0; j < g[to].size(); j++) {
            int v = g[to][j];
            ans[to] -= min(b[to].x + b[v].y, b[to].y + b[v].x);
        }
    }
    for (int i = 0; i < n; i++)
        printf("%I64d ", ans[i]);
    return 0;
}