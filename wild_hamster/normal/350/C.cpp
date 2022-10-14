#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll i,j,x,n,y,m,k,k1,k2,ost,ur,a[100500][2],pos;
pair <ll, ll> b[100500];
ll Abs(ll a)
{
 if (a < 0)
    return -a;
 else
     return a;
}
bool ff(pair <ll, ll> x, pair <ll, ll> y)
{
     if (Abs(x.fi) == Abs(y.fi)) 
        return (Abs(x.se) < Abs(y.se));
     else
         return (Abs(x.fi) < Abs(y.fi));
     
}
int main()
{
cin >> n;
k = 0;
for (i = 0; i < n; i++)
    { 
      cin >> a[i][0] >> a[i][1];
      if (a[i][0] == 0 || a[i][1] == 0) 
         k+=4;
      else
         k+=6;    
    }
for (i = 0; i < n; i++)
    b[i] = mp(a[i][0],a[i][1]);
sort(b, b+n, ff);
for (i = 0; i < n; i++)
    {
     a[i][0] = b[i].fi;
     a[i][1] = b[i].se;
    }
cout << k << endl;
for (i = 0; i < n; i++)
{
 if (a[i][0] < 0)
    cout << 1 <<" "<< -a[i][0] << " L" << endl;
 if (a[i][0] > 0)
    cout << 1 <<" "<< a[i][0] << " R" << endl;
 if (a[i][1] < 0)
    cout << 1 <<" "<< -a[i][1] << " D" << endl;
 if (a[i][1] > 0)
    cout << 1 <<" "<< a[i][1] << " U" << endl;
 cout << 2 << endl;
 if (a[i][0] < 0)
    cout << 1 <<" "<< -a[i][0] << " R" << endl;
 if (a[i][0] > 0)
    cout << 1 <<" "<< a[i][0] << " L" << endl;
 if (a[i][1] < 0)
    cout << 1 <<" "<< -a[i][1] << " U" << endl;
 if (a[i][1] > 0)
    cout << 1 <<" "<< a[i][1] << " D" << endl;
 cout << 3 << endl;
}
return 0;
}