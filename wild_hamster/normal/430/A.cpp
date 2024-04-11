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
ll z,cnt,tmp,l,r,d[500],e[500],n,m,x,y,k,j,p,k1,k2,i,cur,maxlevel,rez;
pair <ll,ll> b[500],c[500],a[500];
string s,s1,s2;
ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
}
int main()
{
   cin >> n >> m;
   for (i = 0; i < n; i++)
   {
       cin >> a[i].first;
       a[i].second = i;       
   }
   sort(a,a+n);
   for (i = 0; i < n; i++)
       d[i] = i%2;
   for (j = 0; j < m; j++)
       cin >> b[j].first >> b[j].second;
   for (i = 0; i < n; i++)
       for (j = 0; j < m; j++)
           if (a[i].first <= b[j].second&&a[i].first >= b[j].first)
              if (d[i]) c[j].second++;
                 else c[j].first++;
   z = 1;
   for (j = 0; j < m; j++)
       if (Abs(c[j].first-c[j].second) > 1) z = 0;
      if (!z)
         cout << -1 << endl;
      else
      {
          for (i = 0; i < n; i++)
              e[a[i].second] = d[i];
          for (i = 0; i < n; i++)
              cout << e[i] << " ";
      } 
   return 0;
}