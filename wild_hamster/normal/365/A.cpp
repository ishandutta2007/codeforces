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
cin >> n >> k;
ll rez = 0;
for (i = 1; i <= n; i++)
{
 string s;
 cin >> s;
 for (j = 0; j < s.size(); j++)
     f[s[j]-'0'] = i;
 bool z = true;
 for (j = 0; j <= k; j++)
     if (f[j] != i)
        z = false;
 if (z) rez++;
}
cout << rez << endl;
return 0;
}