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
typedef int ll;
using namespace std;
ll n,i,j,k,m,q,r,timer,v,tot,x,y,xx, yy,INF, sz,l, z;
vector<int> g[300500];
vector<int> f, f1;
map<pii, ll> pr;
ll b[300500];
void dfs(ll v, ll p = -1) {
    f.push_back(v);
    if (v == n) {
        timer = 1;
        return;
    }
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != p) {
            dfs(to, v);
        }
        if (timer)
            return;
    }
    f.pop_back();
}
void dfs2(ll v, ll p1 = -1, ll p2 = -1) {
    sz++;
    f1.push_back(v);
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != p1 && to != p2) {
            dfs2(to, v);
        }
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back(y);
        g[y].push_back(x);
        pr[mp(x,y)] = pr[mp(y,x)] = z;
    }
    dfs(1);
    tot = 2*MOD;
    for (int i = 0; i < f.size(); i++) {
        int v = f[i];
        int v1 = -1, v2 = -1;
        if (i != 0)
            v1 = f[i-1];
        if (i+1 != f.size())
            v2 = f[i+1];
        sz = 0;
        f1.clear();
        dfs2(v, v1, v2);
        if (sz > 2) {
            tot = -1;
            break;
        } else if (sz == 2) {
            b[i] = pr[mp(f1[0], f1[1])];
        } else
            b[i] = -2*MOD;
        //cout << f[i] << " " << b[i] << endl;
    }
    ll sz = f.size();
    long long sum = 0;
    long long min1 = 2*MOD;
    for (int i = 0; i < sz; i++)  {
        if (i != 0)
            min1 += pr[mp(f[i], f[i-1])];
        min1 = min(min1, 2LL*MOD);
        if (i+2 < sz)
            tot = min(tot, pr[mp(f[i], f[i+1])] + pr[mp(f[i+2], f[i+1])]);
        if (i+1 < sz) {
            tot = min(tot, (int)min(2LL*MOD, 1LL*pr[mp(f[i], f[i+1])] - b[i]));
            tot = min(tot, (int)min(2LL*MOD, 1LL*pr[mp(f[i], f[i+1])] - b[i+1]));
            sum += pr[mp(f[i], f[i+1])];
        }
        tot = min(tot, (int)(min(2LL*MOD, min1 - b[i])));
        if (-b[i] < min1)
            min1 = -b[i];

        //cout << tot << endl;
    }
    //cout << tot << endl;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        if (x < tot)
            printf("%I64d\n", sum - (tot-x));
        else
            printf("%I64d\n", sum);
    }
    return 0;
}