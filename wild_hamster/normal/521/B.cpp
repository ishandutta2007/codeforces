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
#define MOD 1000000009
typedef long long ll;
using namespace std;

ll x,y,w,l,r,i,j,n,k,k1,k2,d,m,q,dr,a[200005],powr[200500],used[200500];
pair<ll,pair<ll,ll> > coord[200500], tr[200500];
map <pair<ll,pair<ll,ll> > , ll> weight;

map <pair<ll,ll>, ll> find_pair;

set <pair<ll,pair<ll,ll> > > f;
set <pair<ll,pair<ll,ll> > >::iterator itr;

vector <ll> g[100500], pred[100500];

bool ff(pair<ll,pair<ll,ll> > x, pair<ll,pair<ll,ll> > y)
{
 if (x.second.second > y.second.second) return true;
 return false;
}
int main()
{
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        coord[i].second.first = x; coord[i].second.second = y;
        coord[i].first = i;
        tr[i] = coord[i];
        find_pair[mp(x,y)] = i+1;
    }
        
    sort(coord,coord+m,ff);
    
    for (i = 0; i < m; i++)
    {
        x = coord[i].second.first; y = coord[i].second.second;
        ll v = coord[i].first;
        //cout << v << endl;
        ll tmp;
        
        tmp = find_pair[mp(x+1,y+1)];
        if (tmp > 0)
        {
         tmp--;
         powr[tmp]++;
         g[tmp].push_back(v);
         pred[v].push_back(tmp);
        }
        
        tmp = find_pair[mp(x,y+1)];
        if (tmp > 0)
        {
         tmp--;
         powr[tmp]++;
         g[tmp].push_back(v);         
         pred[v].push_back(tmp);
        }
        
        tmp = find_pair[mp(x-1,y+1)];
        if (tmp > 0)
        {
         tmp--;
         powr[tmp]++;
         g[tmp].push_back(v);
         pred[v].push_back(tmp);
        }                  
    } 
    
    for (i = 0; i < m; i++)
    {
        x = coord[i].second.first; y = coord[i].second.second;
        ll v = coord[i].first;
        //cout << v << endl;
        ll flag = 1;
        for (j = 0; j < pred[v].size(); j++)
            if (powr[pred[v][j]] == 1)
               flag = 0; 
        if (flag) 
        {
        f.insert(coord[i]);
        }           
    } 
      
    ll pnt = 0;
    ll rez = 0;
    while (f.size() > 0)
    {
     if (pnt == 1)
     {
     itr = f.begin();
     ll v = (*itr).first;
     x = (*itr).second.first;
     y = (*itr).second.second;
     f.erase(*itr);
     used[v] = 1;
     for (i = 0; i < pred[v].size(); i++)
     {
         ll to = pred[v][i];
         if (used[to])
                 continue;
         powr[to]--;
         if (powr[to] == 1)
         for (j = 0; j < g[to].size(); j++)
             if (!used[g[to][j]] && f.find(tr[g[to][j]]) != f.end())
                f.erase(tr[g[to][j]]);
     }
     rez = ((ll)rez*m + v)%MOD;
     for (i = 0; i < g[v].size(); i++)
          {
              ll to = g[v][i];
              if (used[to])
                 continue;
              ll flag = 1;
              for (j = 0; j < pred[to].size(); j++)
                  if (!used[ pred[to][j] ] && powr[pred[to][j]] == 1)
                     flag = 0;
              if (flag)
              {
               f.insert(tr[to]);
              }       
          }
     } else
     {
          itr = f.end();
          itr--;
          ll v = (*itr).first;
     x = (*itr).second.first;
     y = (*itr).second.second;
     f.erase(*itr);
     used[v] = 1;
     for (i = 0; i < pred[v].size(); i++)
     {
         ll to = pred[v][i];
         if (used[to])
                 continue;
         powr[to]--;
         if (powr[to] == 1)
         for (j = 0; j < g[to].size(); j++)
             if (!used[g[to][j]] && f.find(tr[g[to][j]]) != f.end())
                f.erase(tr[g[to][j]]);
     }
     rez = ((ll)rez*m + v)%MOD;
     for (i = 0; i < g[v].size(); i++)
          {
              ll to = g[v][i];
              if (used[to])
                 continue;
              ll flag = 1;
              for (j = 0; j < pred[to].size(); j++)
                  if (!used[ pred[to][j] ] && powr[pred[to][j]] == 1)
                     flag = 0;
              if (flag)
              {
               f.insert(tr[to]);
              }       
          }
     }
     
     pnt = (pnt+1)%2;
    }    
    
    cout << rez << endl;
    return 0;
}