#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <set>
#include <complex>
//#include <cmath>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 100500
#define eps 1e-9
#define PI 3.14159265358979323846
pair<ll,ll> a[100500],b[100500];
ll au[100500],bu[100500];
ll i,j,k,n,x,k1,jk1,j2,k2,k3,y;
int main()
{
cin >> n >> x;
jk1 = j2 = 0;
for (i = 0; i < n; i++)
{
    cin >> k1 >> k2 >> k3;
    if (k1 == 0)
       {
           a[jk1].first = k3;
           a[jk1++].second = k2;
       }
    else
       {
           b[j2].first = k3;
           b[j2++].second = k2;
       }     
}
sort(a,a+jk1);
reverse(a,a+jk1);
sort(b,b+j2);
reverse(b,b+j2);
y = x; ll z = 0;
k1 = 0;
while (1)
{
    if (!z)
    {
           for (i = 0; i < jk1; i++)
               if (a[i].second <= y && !au[i])
               {
                  au[i] = 1;
                  k1++;
                  y+= a[i].first;
                  z = (z+1)%2;
                  break;
               }
           if (!z) break;
    }  else
    
    {
           for (i = 0; i < j2; i++)
               if (b[i].second <= y && !bu[i])
               {
                  bu[i] = 1;
                  k1++;
                  y+= b[i].first;
                  z = (z+1)%2;
                  break;
               }
           if (z) break;
    }
}
y = x; z = 1;
k2 = 0;
for (i = 0; i < 100000; i++)
{
    au[i] = 0;
    bu[i] = 0;
}
while (1)
{
    if (!z)
    {
           for (i = 0; i < jk1; i++)
               if (a[i].second <= y && !au[i])
               {
                  au[i] = 1;
                  k2++;
                  y+= a[i].first;
                  z = (z+1)%2;
                  break;
               }
           if (!z) break;
    }  else
    
    {
           for (i = 0; i < j2; i++)
               if (b[i].second <= y && !bu[i])
               {
                  bu[i] = 1;
                  k2++;
                  y+= b[i].first;
                  z = (z+1)%2;
                  break;
               }
           if (z) break;
    }
}
cout << max(k1, k2) << endl;
return 0;
}