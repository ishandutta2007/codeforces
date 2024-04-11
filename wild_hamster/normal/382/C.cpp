#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <set>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 5000
#define NN 25000000
vector <ll> lal;
ll d,i,j,t,i1,m,n,k,x,y,x1,x2,y1,y2,rez,b[1000500],c[1000500],k1,k2,n1,m1;
ll a[1000500];
map <ll,ll> g, g1;
vector <ll> f;
ll gcd(ll a, ll b)
{
 if (b == 0) return a;
    else return gcd(b,a%b);
}
ll Abs(ll a)
{
if (a > 0) return a;
   return -a;
}
string s1,s2,s3,s;
int main()
{

cin >> n;
for (i = 0; i < n; i++)
    cin >> a[i];
sort(a, a + n);
if (n == 1)
   {
         cout << -1 << endl;
         return 0;
   }
ll z = 0;
for (i = 0; i < n - 1; i++)
    if (a[i] != a[i+1]) z = 1;
if (!z)
{
    cout << 1 << endl << a[0] << endl;
    return 0;
}
if (n == 2)
   {
       if ((a[1] - a[0]) % 2 == 0)
       {
           cout << 3 << endl;
           ll d = (a[0] + a[1]) / 2;
           cout << 2 * a[0] - a[1] << " " << d << " " << 2 * a[1] - a[0] << endl;
       }
       else
       {
           cout << 2 << endl;
           cout << 2 * a[0] - a[1] << " " << 2 * a[1] - a[0] << endl;
       }
       return 0;
   }
for (i = 0; i < n - 1; i++)
{
    d = a[i+1] - a[i];
    if (g[d] == 0) 
    {
       g[d]++;
       k++;
       f.pb(d);
       g1[d] = a[i];
    } else
    g[d]++;
}
sort(f.begin(),f.end());
if (k == 1)
{
      cout << 2 << endl;
      cout << a[0] - d << " " << a[n-1] + d << endl;
      return 0;
} 
if (k == 2)
{
      if (f[1] == f[0]*2 && g[f[1]] == 1)
      {
      cout << 1 << endl;
      cout << g1[f[1]] + f[0] << endl;
      return 0;
      }   
} 
cout << 0 << endl;
return 0;
}