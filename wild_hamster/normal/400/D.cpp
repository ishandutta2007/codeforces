#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
typedef long long ll;
using namespace std;
ll i,j,n,l,r,rez,k,m,y,z,q,k1,k2,x,a[100500],used[100500],b[600],d[600][600],next,p,tmp;
ll c[100500];
vector <ll> f[600];
vector <ll> graph[100500];
vector <ll> comps;
string s;
void dfs(int v)
{
     //cout << v << endl;
   used[v] = 1;
   comps.push_back(v);
   for (int i = 0; i < graph[v].size(); i++)
   if (!used[graph[v][i]])
       dfs(graph[v][i]);  
}
int main()
{
    cin >> n >> m >> k;
    tmp = 1;
    for (i = 0; i < k; i++)
    {
        cin >> x;
        b[i] = tmp;
        for (j = tmp; j < tmp+x; j++)
        {
            f[i].push_back(j);
            a[j] = i;
        }
        tmp += x;
    }
    for (i = 0; i < k; i++)
        for (j = 0; j < k; j++)
            if (i == j) d[i][j] = 0;
               else d[i][j] = -1;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        if (z == 0) 
        {
        graph[x].push_back(y);
        graph[y].push_back(x);
        }
        if (d[a[x]][a[y]] == -1)
        {
           d[a[x]][a[y]] = z;
           d[a[y]][a[x]] = z;
        }
        else
        {
            d[a[x]][a[y]] = min(d[a[x]][a[y]],z);
            d[a[y]][a[x]] = min(d[a[y]][a[x]],z);
        }
    }
    for (i = 0; i < k; i++)
    {
        //cout << b[i] << endl;
        for (j = 1; j <= n; j++)
            used[j] = 0;
        dfs(b[i]);
        x = b[i];
        ll flag = 1;
        for (j = 0; j < comps.size(); j++)
        {
            c[comps[j]] = 1;
        }
        while (a[b[i]] == a[x] && x <= n)
        {             
              if (c[x] == 0)
                 flag = 0;
              x++;              
        }
        for (j = 0; j < comps.size(); j++)
            c[comps[j]] = 0;
        comps.clear();
        if (!flag)
        {
         cout << "No" << endl;
         return 0;
        }
    }
    cout << "Yes" << endl;
    for (x = 0; x < k; x++)
        for (i = 0; i < k; i++)
            for (j = 0; j < k; j++)
            if (d[x][i]!=-1&&d[x][j]!=-1)
            {
               if (d[i][j] != -1)
               d[i][j] = min(d[i][j],d[x][i]+d[x][j]);
               else
               d[i][j] = d[x][i]+d[x][j];
            }
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }
    return 0;
}