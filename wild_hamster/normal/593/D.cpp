#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 (33LL+(ll)1e+17)
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
typedef long long ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag,timer;
vector <ll> divisors;
map<pii,ll> ff;
pii edges[N];
ll f[N];
ll a[N], b[N], up[258228][20], tin[N], tout[N], up_with[N];
string s;
vector <ll> g[N];
void dfs (int v, int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (int i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
        {
            dfs (to, v);
        }
    }
    tout[v] = ++timer;
}



bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

ll lca (ll a, ll b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}
ll F(ll v)
{
    if (v == 0)
       return v;
    if (f[v] > 1)
       return v;
    
    return up[v][0] = F(up[v][0]);
}
int main()
{
    ll q;
    cin >> n >> q;
    l = 18;
    for (i = 1; i < n; i++)
    {
        scanf("%I64d%I64d%I64d",&x,&y,&z);
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
        edges[i] = mp(x,y);
        ff[mp(x,y)] = ff[mp(y,x)] = z;
    }

    dfs(0);
    for (i = 1; i < n; i++)
    {
        f[i] = ff[mp(i,up[i][0])];
    }
    while (q--)
    {
        ll tt;
        scanf("%I64d",&tt);
        if (tt == 1)
        {
            scanf("%I64d%I64d%I64d",&x,&y,&z);
            x--;y--;
            ll lc = lca(x,y);
            //cout << "lca=" << lc << endl;
            while (!upper(x,lc) && z != 0)
            {
                //cout << x+1 << endl;
                x = F(x);
                //cout << "after" << x+1 << endl;
                if (upper(x,lc))
                   break;
                z /= f[x];
                //cout << "Z=" << z << endl;
                x = up[x][0];
            }
            x = y;
            while (!upper(x,lc) && z != 0)
            {
                //cout << x+1 << endl;
                x = F(x);
                //cout << "after" << x+1 << endl;
                if (upper(x,lc))
                   break;
                z /= f[x];
                //cout << "Z=" << z << endl;
                x = up[x][0];
            }
            printf("%I64d\n",z);
        } else
        {
            scanf("%I64d%I64d",&x,&y);
            //cout << "kaka" << endl;
            ll fi = edges[x].X;
            ll se = edges[x].Y;
            if (se == up[fi][0])
               f[fi] = y;
            else
                f[se] = y;
            //cout << "bla" << endl;
        }
    }
    return 0;
}