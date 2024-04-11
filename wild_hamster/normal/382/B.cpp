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
ll a,b,w,x,c,i,j;
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
ll counter = 0;
cin >> a >> b >> w >> x >> c;
if (c <= a)
{
      cout << 0 << endl;
      return 0;
}
while (b >= x)
{
      b -= x;
      counter++;
      c--;
      if (c <= a)
      {
       cout << counter << endl;
       return 0;
      }
}
ll t = ((c-a) / (w-x)) - 1;
counter += t*w;
c -= t*w;
a -= t*x;
while (c > a)
{
      counter++;
      c--;
      if (b >= x) b -= x;
      else 
      {
         a--;
         b += (w-x);
      }
}
cout << counter << endl;
return 0;
}