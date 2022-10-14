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
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define MAXN 100100
typedef long long ll;
using namespace std;
ll x,y,l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,z,max1,tx,pnt,flag;
ll a[105][105],b[105][105],used[105],glob_used[105],d[105][105];
vector <ll> g[1005];
vector <pii> todo;
vector <ll> bla, res;
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        g[x].push_back(y);
        g[y].push_back(x);
        a[x][y] = a[y][x] = z;
        d[x][y] = d[y][x] = 1;
    }
    for (int vert = 1; vert <= n; vert++)
    if (!glob_used[vert])
       {
       todo.clear();
       bla.clear();
       for (i = 1; i <= n; i++)
           used[i] = 0;
       used[vert] = 1;
       for (i = 0; i < g[vert].size(); i++)
       {
        todo.push_back(mp(g[vert][i],vert));
        used[g[vert][i]] = vert;
       }
       for (i = 1; i <= n; i++)
           for (j = 1; j <= n; j++)
               b[i][j] = a[i][j];
       i = 0;
       while (i < todo.size())
       {
        ll v = todo[i].first;
        ll prv = todo[i].second;
        i++;
        if (b[v][prv] == 0)
        {
            bla.push_back(v);
           for (j = 0; j < g[v].size(); j++)
           {
               ll to = g[v][j];
               b[v][to] ^= 1;
               b[to][v] ^= 1;
               if (!used[to])
               {
                used[to] = 1;
                todo.push_back(mp(to,v));
               }
           }
        } else
        {
           for (j = 0; j < g[v].size(); j++)
           {
               ll to = g[v][j];
               if (!used[to])
               {
                used[to] = 1;
                todo.push_back(mp(to,v));
               }
           }
        }
       }
       ll tmp = 0;
       for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (used[i] && used[j])
            tmp += b[i][j] - d[i][j];
       if (tmp == 0)
       {
        for (i = 0; i < bla.size(); i++)
            res.push_back(bla[i]);
        for (i = 1; i <= n; i++)
            if (used[i])
               glob_used[i] = 1;
        continue;
       }
    
    for (i = 1; i <= n; i++)
        used[i] = 0;
    used[vert] = 1;
    todo.clear();
    bla.clear();
    bla.push_back(vert);

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            b[i][j] = a[i][j];
    for (i = 0; i < g[vert].size(); i++)
    {
        todo.push_back(mp(g[vert][i],vert));
        b[g[vert][i]][vert] ^= 1;
        b[vert][g[vert][i]] ^= 1;
        used[g[vert][i]] = 1;
    }
    i = 0;
    while (i < todo.size())
    {
        ll v = todo[i].first;
        ll prv = todo[i].second;
        i++;
        if (b[v][prv] == 0)
        {

           bla.push_back(v);
           for (j = 0; j < g[v].size(); j++)
           {
               ll to = g[v][j];
               if (!used[to])
               {
                used[to] = 1;
                todo.push_back(mp(to,v));
               }
           }
        } else
        {
           for (j = 0; j < g[v].size(); j++)
           {
               ll to = g[v][j];
               if (!used[to])
               {
                used[to] = 1;
                todo.push_back(mp(to,v));
               }
           }
        }
    }
    tmp = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (used[i] && used[j])
            tmp += b[i][j]-d[i][j];
    if (tmp == 0)
    {
        for (i = 0; i < bla.size(); i++)
            res.push_back(bla[i]);
        for (i = 1; i <= n; i++)
            if (used[i])
               glob_used[i] = 1;
        continue;
    }
    cout << "Impossible" << endl;
    return 0;
    }
    cout << res.size() << endl;
    for (i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}