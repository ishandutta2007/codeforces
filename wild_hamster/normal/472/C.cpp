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
ll z[400500],cnt,tmp,l,r,n,m,k,j,p,k1,k2,i;
ll a[500000],dp[500000];
pair <string,string> s[100500],rez[100500];
bool xMy(string x, string y)
{
     int i;
     int n = min(x.size(), y.size());
     for (i = 0; i < n; i++)
         if (x[i] < y[i]) return true;
     else if (x[i] > y[i]) return false;
     if (x.size() > y.size()) return false;
     else return true;
}
int main()
{
   cin >> n;
   for (i = 0; i < n; i++)  
   {
       cin >> s[i].first >> s[i].second;
   } 
   for (i = 0; i < n; i++)
       cin >> a[i];
   ll z = 1;
   for (i = 0; i < n; i++)
   {
       rez[i] = s[a[i]-1];
       if (!xMy(rez[i].first,rez[i].second)) swap(rez[i].first,rez[i].second);
   }
   string tmp;
   tmp = rez[0].first;
   for (i = 1; i < n; i++)
   {
       if (xMy(tmp,rez[i].first))
          tmp = rez[i].first;
       else
       if (xMy(tmp,rez[i].second))
          tmp = rez[i].second;
       else
           z = 0;
   }
   if (z) cout << "YES" << endl;
   else cout << "NO" << endl;
   return 0;
}