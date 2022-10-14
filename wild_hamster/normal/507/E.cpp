#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
string s;
ll an[100500],bn[100500],n,i,j,d,x,k,y,m,l,r,c,sum,used[100500],a[100500],b[100500];
vector <pair<ll,ll> > graph[100500];
vector <ll> strange;
map <pair<ll,ll>,ll> dno;
struct azaza
{
 ll x, y, w;
};
azaza t[100500];
int main()
{
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y >> r;
        graph[x].pb(mp(y,r));
        graph[y].pb(mp(x,r));
        sum += r;
        t[i].x = x;
        t[i].y = y;
        t[i].w = r;
    }
    strange.pb(1);    
    for (i = 2; i <= n; i++)
        a[i] = n+5, an[i] = n+5;
    i = 0;
    a[1] = 0;
    b[1] = 0;
    used[1] = 1;
    while (i < strange.size())
    {
          ll v = strange[i];
          for (j = 0; j < graph[v].size(); j++)
          {
              ll to = graph[v][j].first;
              ll w = graph[v][j].second;
              if (!used[to])
              {
               used[to] = 1;
               strange.pb(to);
               a[to] = a[v] + 1;
               b[to] = b[v] + w;
              } else
              if (a[to] == a[v] + 1)
              {
               b[to] = max(b[to],b[v]+w);
              }
          }
          i++;
    }
    strange.clear();
    
    for (i = 1; i <= n; i++)
        used[i] = 0;
    strange.pb(n);
    i = 0;
    an[n] = 0;
    bn[n] = 0;
    used[n] = 1;
    while (i < strange.size())
    {
          ll v = strange[i];
          for (j = 0; j < graph[v].size(); j++)
          {
              ll to = graph[v][j].first;
              ll w = graph[v][j].second;
              if (!used[to])
              {
               used[to] = 1;
               strange.pb(to);
               an[to] = an[v] + 1;
               bn[to] = bn[v] + w;
              } else
              if (an[to] == an[v] + 1)
              {
               bn[to] = max(bn[to],bn[v]+w);
              }
          }
          i++;
    }
    
    ll rez = 0;
    for (i = 1; i <= n; i++)
    if (a[i]+an[i] == a[n])
    {
        rez = max(rez, b[i]+bn[i]);
    }
    cout << sum + a[n] - 2*rez << endl;
    
    strange.clear();
    for (i = 0; i <= n; i++)
        used[i] = 0;
    i = 0;
    strange.pb(1);
    while (i < strange.size())
    {
          ll v = strange[i];
          ll tmp = 0;
          for (j = 0; j < graph[v].size(); j++)
          {
              ll to = graph[v][j].first;
              ll w = graph[v][j].second;
              if (a[to]+an[to] == a[n] && b[to]+bn[to] == rez && a[to] == a[v] + 1)
              {
               tmp = to;
               break;
              }
          }
          if (tmp > 0) 
          {
                  dno[mp(v,tmp)] = 1;
                  dno[mp(tmp,v)] = 1;
          }
          if (tmp > 0) strange.pb(tmp);
          i++;
    }
    for (i = 0; i < m; i++)
    {
        if (t[i].w == 0&&dno[mp(t[i].x,t[i].y)] == 1)
        {
         cout << t[i].x << " " << t[i].y << " " << 1 << endl;
        }
        
        if (t[i].w == 1&&dno[mp(t[i].x,t[i].y)] == 0)
        {
         cout << t[i].x << " " << t[i].y << " " << 0 << endl;
        }
    }
    return 0;
}