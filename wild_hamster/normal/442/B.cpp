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
struct lalka
{
       ll r1,r2,r3;
};
bool ff(lalka a, lalka b)
{
     if (a.r1 > b.r1) return true;
     return false;
}
double a[500],x0,x1,yy0,yy1;
ll used[500];
ll i,j,l,r,k,n,k1,jk1,j2,k2,k3,y,m,w;
string s;
int main()
{
cin >> n;
for (i = 0; i < n; i++)
    cin >> a[i];
sort(a,a+n);
used[n-1] = 1;
x0 = 1 - a[n-1]; x1 = a[n-1];
bool z = true;
while (z)
{
      z = false;
      for (i = n-1; i >= 0; i--)
          if (!used[i] && x1*(1 - a[i]) + x0*a[i] > x1)
          {
                       used[i] = 1;
                       z = true;
                       yy1 =  x1*(1 - a[i]) + x0*a[i];
                       yy0 = x0*(1 - a[i]);
                       x1 = yy1;
                       x0 = yy0;
                       break;
          }
}
printf("%.12f\n",x1);
return 0;
}