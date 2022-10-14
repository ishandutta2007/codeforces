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
ll i,n,j,k,k1,d,x,m,a[100500],dp[500500],poss_sum[500500];
ll f[500500];
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
cin >> n;
for (i = 0; i < n; i++)
    cin >> a[i];
if (n < 3)
{ 
   cout << n << endl;
   return 0;
}
for (i = 2; i < n; i++)
    if (a[i] == a[i-1] + a[i-2])
       f[i] = 1;
ll rez = 2, tmp = 2;
for (i = 2; i <= n; i++)
    {
         if (f[i]) tmp++;
            else
                {
                 rez = max(rez,tmp);
                 tmp = 2;
                }
    }
cout << rez << endl;
return 0;
}