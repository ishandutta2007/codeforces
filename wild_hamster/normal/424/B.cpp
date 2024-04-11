#include <iostream>
#include <cmath>
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
ll a[100500],z,cnt,tmp,e,l,r,s,n,m,j,p,k1,k2,i,cur,rez;
vector <ll> f,g,primes[100500];
ll x[1000500],y[1000500],k[1000500];
int main()
{   
   cin >> n >> s;
   ll sum = 0;
   for (i = 0; i < n; i++)
   {
       cin >> x[i] >> y[i] >> k[i];
       sum += k[i];
   }
   if (s+sum < 1000000)
   {
    cout << -1 << endl;
    return 0;
   }
   double l = 0, r = 100000;
   while (r-l > 1e-9) 
   {
         double mid = (l+r)/2.;
         ll tmp = 0;
         for (i = 0; i < n; i++)
             if (x[i]*x[i]+y[i]*y[i] <= mid*mid)
         tmp += k[i];
         if (tmp + s < 1000000)
            l = mid;
         else
             r = mid;
   }
   printf("%.7f\n",l);
   return 0;
}