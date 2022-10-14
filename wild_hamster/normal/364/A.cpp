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
vector <ll> azaza;
ll i,n,j,k,x,m,a[100500],dp[4005][4005],b[100500],c[50000];
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
ll find_sum(ll x)
{
ll i = 0, rez = 0;
ll y = 0, pointer = 0;
while (i < n)
      {
      if (y == x) 
         {
          rez++;
          y += a[i];
          i++;
          continue;
         }
      if (y < x)
         {
          y += a[i];
          i++;   
          continue;
         }
      y -= a[pointer];
      pointer++;
      }
      return rez;
}
int main()
{
cin >> x;
string s;
cin >> s;
n = s.size();
b[0] = 0;
for (i = 0; i < s.size(); i++)
{
    a[i] = s[i] - '0';
    b[i+1] = b[i] + a[i];
}
//cin >> m >> k;
//cout << b[k+1] - b[m] << endl;
for (i = 0; i < n; i++)
    for (j = i; j < n; j++)
    {
        dp[i][j] = b[j+1] - b[i];
           c[ dp[i][j] ]++;
    }
ll rez = 0;
if (x == 0)
   { 
   rez = ((n*(n+1))/2)*c[0];
   }
for (i = 1; i < 40000; i++)
    if (x%i == 0 && x/i < 40000)
    {
         rez += c[x/i]*c[i];
    }
cout << rez << endl;
return 0;
}