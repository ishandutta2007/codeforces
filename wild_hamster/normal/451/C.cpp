#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll m,i,n,k,j,a[300500],b[300500],t,x,y,z,d1,d2,rez;
ll rakun(ll x, ll y)
{
     if (x > y) swap(x,y);
     if (x < 0)
     {
      ll z = -x;
      y -= x;
      if (y > z) swap(y,z);
      if ((k-y-z)%3!=0 || y+z>k) return 0;
        else
            z+=(k-y-z)/3;
     // cout << y << " " << z << endl;
      if (z*3 <= n) return 1;
      return 0;
     }
     else
     {
        // cout << x << " " << y << endl;
        if ((k-x-y)%3!=0 || x+y>k) return 0;
        else
            y+=(k-x-y)/3;
         if (y*3 <= n) return 1;
         return 0;
     }
}
int main()
{
    cin >> t;
    for (i = 0; i < t; i++)
    {
        m = 0;
        cin >> n >> k >> d1 >> d2;
        if (rakun(d1,d1-d2)) m = 1;
        if (rakun(d1,d1+d2)) m = 1;
        if (rakun(-d1,-d1-d2)) m = 1;
        if (rakun(-d1,-d1+d2)) m = 1;   
        if (n%3!=0) m = 0;
        if (m)
           cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}