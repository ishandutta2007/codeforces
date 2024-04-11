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
ll s,i,j,m,n,k,x,y,x1,x2,y1,y2,rez,b,k1,k2;
ll a[300500];
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
int main()
{
ll sum = 0;
cin >> n;
for (i = 0; i < n; i++)
{
    cin >> a[i];
    sum += a[i];
}
i = 0;
ll z;
while (sum)
{
      if (i == 0) z = 1;
      if (i == n - 1) z = -1;
      if (a[i]) { a[i]--; sum--; cout << 'P';}
      if (sum == 0) break;
      if (z == 1) {cout << 'R'; i++;}
      else {cout << 'L'; i--;}
}
return 0;
}