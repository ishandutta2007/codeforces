#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll n,m,i,j,rez,a[100500],b[100500],rizn[200500],x,k,y,l,r;

int main()
{
    cin >> n >> m >> k;
    for (i = 0; i < n; i++)
        cin >> a[i];
    l = 0; r = (ll)1e+10;
    while (l<r)
    {
         // cout << l << " " << r << endl;
          ll mid = (l+r+1)/2;
          for (i = 0; i < 100500; i++)
              rizn[i] = 0;
          for (i = 0; i < n; i++)
          b[i] = mid - a[i];
          ll tmprez = 0,tmp = 0;
          for (i = 0; i < n; i++)
          {
              tmp += rizn[i];
              b[i] += tmp;
              b[i] = max(b[i],(ll)0);
              tmprez += b[i];
              tmp -= b[i];
              rizn[i+k] += b[i];
          }
          
          if (tmprez <= m)
             l = mid;
          else
              r = mid-1;
    }
    cout << l << endl;
    return 0;
}