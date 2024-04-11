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
ll n,m,j,p,t,l,r,h,x,y,a[100500],k,i,w,rez,used[100500];
vector <ll> graph1[100500], graph2[100500];
vector <ll> components,orders;
void dfs1(ll v)
{
     used[v] = 1;
     for (int i = 0; i < graph1[v].size(); i++)
     if (!used[graph1[v][i]])
         dfs1(graph1[v][i]);
     orders.push_back(v);
}
void dfs2(ll v)
{
     used[v] = 1;
     components.push_back(v);
     for (int i = 0; i < graph2[v].size(); i++)
     if (!used[graph2[v][i]])
         dfs2(graph2[v][i]);
}
int main()
{
   cin >> n;
   for (i = 1; i <= n; i++) 
       cin >> a[i];
   cin >> m;
   for (i = 0; i < m; i++)
   {
       cin >> x >> y;
       graph1[x].push_back(y);
       graph2[y].push_back(x);
   }
   for (i = 1; i <= n; i++)
   if (!used[i])
       dfs1(i);
   reverse(orders.begin(),orders.end());
   for (i = 0; i <= n; i++)
       used[i] = 0;
   k = 0;
   rez = 1;
   for (i = 0; i < n; i++)
   if (!used[orders[i]])
   {
    dfs2(orders[i]);
    for (j = 0; j < components.size(); j++)
        components[j] = a[components[j]];
    sort(components.begin(),components.end());
    k += components[0];
    j = 0;
    ll tmp = 0;
    while (components[j] == components[0] && j < components.size())
          tmp++, j++;
    components.clear();
    rez = (rez*tmp)%tr;
   }
   cout << k << " " << rez << endl;
   return 0;
}