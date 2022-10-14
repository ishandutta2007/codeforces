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
ll a[100500],z,cnt,tmp,l,r,used[100500],n,m,x,y,k,j,p,k1,k2,i,cur,maxlevel;
vector <ll> tree[100500];
string s,s1,s2;
vector <ll> rez;
ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
}
ll dfs(ll v, ll lvl, ll need0, ll need1)
{
 used[v] = 1;
 if (lvl%2 == 0)
 {
  if ((need0^a[v]) == 1)
  {
   need0 ^= 1;
   rez.push_back(v);
  } 
 } else
 {
  if ((need1^a[v]) == 1)
  {
   need1 ^= 1;
   rez.push_back(v);
  } 
 }
 for (int i = 0; i < tree[v].size(); i++)
 {
     ll cur = tree[v][i];
     if (!used[cur])
        dfs(cur,lvl+1,need0,need1);
 }
}
int main()
{
   cin >> n;
   for (i = 0; i < n-1; i++)
   {
       cin >> x >> y;
       tree[x].push_back(y);
       tree[y].push_back(x);
   }
   for (i = 1; i <= n; i++)
       cin >> a[i];
   for (i = 1; i <= n; i++)
       {
            cin >> x;
            a[i]^=x;
       }
   dfs(1,0,0,0);
   cout << rez.size() << endl;
   for (i = 0; i < rez.size(); i++)
       cout << rez[i] << endl;
   return 0;
}