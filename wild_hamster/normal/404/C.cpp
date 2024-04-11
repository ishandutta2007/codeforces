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
typedef long long ll;
using namespace std;
ll s,n,m,j,p,l,r,x,y,d[100500],k1,k2,k3,k4,k,i,cur,kokoko;
pair <ll,ll> a[100500];
vector <pair<ll,ll> > rez;
deque <ll> f[100500];
int main()
{
   cin >> n >> m;
   for (i = 0; i < n; i++)
   {
       cin >> a[i].first; 
       a[i].second = i+1;
   }
   if (n == 1)
   {
         if (a[i].first == 0) cout << 0 << endl;
         else cout << -1 << endl;
         return 0;
   }
   sort(a,a+n);
   if ((a[0].first == 0 && a[1].first == 0)||a[0].first != 0)
   {
    cout << -1 << endl;
    return 0;
   }
   f[0].push_back(a[0].second);
   d[a[0].second] = 0;
   ll z = 1;
   for (i = 1; i < n; i++)
   {
       ll tmp = a[i].first - 1;
       if (f[tmp].size() == 0) z = 0; else
       if (d[f[tmp].front()] == m) z = 0;
       else
       {
           rez.push_back(mp(f[tmp].front(),a[i].second));
           d[f[tmp].front()]++;
           f[tmp].push_back(f[tmp].front());
           f[tmp].pop_front();
       }
       d[a[i].second] = 1;
       f[tmp+1].push_back(a[i].second);
   }
   if (z == 0)
      cout << -1 << endl;
   else
   {
    cout << rez.size() << endl;
    for (i = 0; i < rez.size(); i++)
        cout << rez[i].first << " " << rez[i].second << endl;
   }
   
   return 0;
}