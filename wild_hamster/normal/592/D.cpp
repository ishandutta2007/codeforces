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
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag,diameter;
vector <ll> divisors;
ll a[N], weight[N], marked[N], d[N], ps[N], maxd1[N], maxd2[N], anc1[N], anc2[N], pr[N];
vector<ll> g[N];
string s,t;
vector <ll> f;
void dfs(ll v, ll p = -1)
{
    weight[v] = 0;
    anc1[v] = anc2[v] = v;
    ll bull = d[v], bull2 = 0;
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (to != p)
        {
            pr[to] = v;
            d[to] = d[v] + 1;
            dfs(to,v);
            if (weight[to] != 0 || marked[to])
            {
                if (maxd1[to] >= bull)
                {
                    bull2 = bull;
                    anc2[v] = anc1[v];
                    bull = maxd1[to];
                    anc1[v] = anc1[to];
                } else
                if (maxd1[to] >= bull2)
                {
                    bull2 = maxd1[to];
                    anc2[v] = anc1[to];
                }
               weight[v] += weight[to]+2;
            }
        }
    }
    maxd1[v] = bull; maxd2[v] = bull2;
    if (bull + bull2 - 2*d[v] >= diameter)
    {
        diameter = bull + bull2 - 2*d[v];
        k1 = anc1[v];
        ll tmp = diameter/2;
        k2 = tmp;
    }
}
void dfs2(ll v, ll p, ll ch)
{
    ps[v] = ch;
     for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (to != p)
        {
            dfs2(to,v,ch);
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
   cin >> n >> m;
   for (i = 0;i < n-1; i++)
   {
    scanf("%I64d %I64d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
   }
   for (i = 0; i < m; i++)
   {
       scanf("%I64d",&a[i]);
       marked[a[i]] = 1;
   }
   ll frst = a[0];
   d[frst] = 0;
   dfs(frst);
   r = diameter;
   ll x = k1;
   while (k2)
   {
    k2--;
    x = pr[x];
   }
   if (m == 1)
   {
    cout << frst << endl << 0 << endl;
    return 0;
   }
   //cout << x << endl;
   for (i = 1; i <= n; i++)
       d[i] = maxd1[i] = maxd2[i] = 0;
   //cout << x << endl;
   dfs(x);
   ps[x] = x;
   for (i = 0; i < g[x].size(); i++)
   {
    ll v = g[x][i];
    //cout << v << " ";
    dfs2(v,x,v);
   }
   maxd1[x] = 0;
   ll k = n+2;
   for (i = 0; i < m; i++)
   {
    //cout << a[i] << " " << ps[a[i]] << " " << maxd1[a[i]] << " " << d[a[i]] << endl;
    if (d[a[i]] == maxd1[a[i]] && maxd1[a[i]] == maxd1[ps[a[i]]] && maxd1[a[i]] >= k2)
    {
        if (k > a[i])
        {
           k = a[i];
        }
    }
   }
   x = k;
   dfs(x);
   //cout << r << endl;
   cout << x << endl << weight[x]-r << endl;
    return 0;
}