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
cin >> n >> d;
for (i = 0; i < n; i++)
    cin >> a[i];
sort(a,a+n);
if (a[0] > d)
   {
    cout << "0 0" << endl;
    return 0;
   }
poss_sum[0] = 1;
poss_sum[a[0]] = 1;
for (i = 1; i < n; i++)
    {
         for (j = 500100; j >= 0; j--)
             if (poss_sum[j])
                poss_sum[j+a[i]] = 1;
    }
k1 = 0;
for (i = 0; i < 500500; i++)
    if (poss_sum[i])
       f[k1++] = i;
for (i = 0; i <= 500400; i++)
    dp[i] = 5100500;
//for (i = 0; i < k1; i++)
//    cout << f[i] << " ";
//cout << endl;
dp[0] = 0;
for (i = 0; i < 500500; i++)
    if (poss_sum[i])
    {
       ll tmp = upper_bound(f,f+k1,i+d) - f - 1;
       //cout << i+d << " " << tmp << " " << f[tmp] << endl;
       tmp = f[tmp];       
       dp[tmp] = min(dp[tmp],dp[i]+1);
    }
for (i = 500400; i >= 0; i--)
    if (dp[i] < 1000000)
       {
              cout << i << " " << dp[i] << endl;
              break;
       }
return 0;
}