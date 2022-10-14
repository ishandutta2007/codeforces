#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll z,cnt,tmp,l,r,n,m,k,j,p,k1,k2,i,cur,maxlevel,rez,color[2005],amnt[2005];
ll a[2005][2005],used[2010][2010],used1[2010],lca[2010][2010],level[2010],parent[2005];
vector<pair <ll,pair<ll,ll> > > b;
vector <ll> ver[2005];
vector <ll> tree[2005];
vector <ll> levels[2005],anc[2005];
void dfs(int v, int lvl)
{
     used1[v] = 1;
     level[v] = lvl;
     levels[lvl].push_back(v);
     maxlevel = max(maxlevel,(ll)lvl);
     for (int i = 0; i < ver[v].size(); i++)
     if (!used1[ver[v][i]])
     {
      parent[ver[v][i]] = v;
      tree[v].push_back(ver[v][i]);
      dfs(ver[v][i],lvl+1);
     }
        
}
void colorIt(int x, int y)
{
     color[x] = color[y];
     for (int i = 0; i < ver[x].size(); i++)
     if (color[y] != color[ver[x][i]])
     {
         int v = ver[x][i];
         colorIt(v,y);
     }
}
int main()
{
   cin >> n;
   for (i = 0; i < n; i++)
       for (j = 0; j < n; j++)
           scanf("%d",&a[i][j]);
   if (n == 1)
   {
         if (a[0][0] == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
         return 0;
   } else
   if (n == 2)
   {
         if (a[0][0] == 0 && a[1][1] == 0 && a[0][1] == a[1][0] && a[0][1]!=0)
            cout << "YES" << endl;
         else cout << "NO" << endl;
         return 0;
   }
   for (i = 0; i < n; i++)
   {
   if (a[i][i]!=0)
   {
    cout << "NO" << endl;
    return 0;
   }
       for (j = i+1; j < n; j++)
           if (a[i][j]!=a[j][i]||a[i][j] == 0)
           {
            cout << "NO" << endl;
            return 0;
           }
   }
   z = 1;
   for (i = 0; i < n; i++)
       for (j = i+1; j < n; j++)
           b.push_back(mp(a[i][j],mp(i,j)));
   for (i = 0; i < n; i++)
       color[i] = i;
   sort(b.begin(),b.end());
   for (i = 0; i < b.size(); i++)
   {
   ll x = b[i].second.first, y = b[i].second.second;
      if (color[x]!=color[y])
      {
         used[x][y] = 1; used[y][x] = 1;
         colorIt(x,y);
         ver[x].push_back(y);
         ver[y].push_back(x);
         rez++;
         
      }
      
   }
 /* for (i = 0; i < n; i++)
   {
       for (j = 0; j < ver[i].size(); j++)
           cout << ver[i][j] << " ";
       cout << endl;
   }*/
   maxlevel = 0;
   for (i = 0; i < n; i++) used1[i] = 0;
   dfs(0,0);
   for (i = 0; i < 2001; i++)
       for (j = 0; j < 2001; j++)
           lca[i][j] = -1;
   for (i = 0; i < n; i++)
       anc[i].push_back(i);
   for (i = 0; i < n; i++)
       amnt[i] = 0;
   for (i = maxlevel; i >= 1; i--)
   {
       for (j = 0; j < levels[i].size(); j++)
       {
        
        ll curpar = parent[levels[i][j]];
        for (int x = 0; x < anc[levels[i][j]].size(); x++)
        {
        ll cur = anc[levels[i][j]][x];        
        if (a[curpar][cur] != amnt[cur]+a[curpar][levels[i][j]])              
             z = 0;
        amnt[cur] = a[curpar][cur];
       // cout << cur << " " << i << " " << curpar << endl;
        for (k = 0; k < anc[curpar].size(); k++)
            if (lca[cur][anc[curpar][k]] == -1)
            {
             lca[cur][anc[curpar][k]] = curpar;
             lca[anc[curpar][k]][cur] = curpar;             
            }        
        }
        for (int x = 0; x < anc[levels[i][j]].size(); x++)
        anc[curpar].push_back(anc[levels[i][j]][x]);
       }
   }
   for (i = 0; i < n; i++)
       lca[i][i] = i;
  /* if (n == 22)
   for (i = 0; i < 9; i++)
   {
       for (j = 0; j < 9; j++)
           cout << lca[i][j] << " ";
       cout << endl;
   }*/
     for (i = 0; i < n; i++)
         for (j = i; j < n; j++)
         {
             ll tmp = lca[i][j];
             if (tmp == -1) cout << maxlevel << " " << i << " " << j << " " <<rez << endl;
             //cout << tmp << " " << i << " " << j << endl;
             if (a[tmp][i]+a[tmp][j]!=a[i][j]) z = 0;
         }
   if (z && rez== n - 1) cout << "YES" << endl;
      else cout << "NO" << endl;
   return 0;
}