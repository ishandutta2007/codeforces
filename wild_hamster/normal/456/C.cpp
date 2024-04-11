#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll t[400500],z[400500],rez,l,r,n,m,k,j,p,k1,k2,i;
ll a[500000],dp[500000];
string s;
int main()
{
   cin >> n;
   for (i = 0; i < n; i++)
   {
       cin >> p;
       a[p] += p;
   }
   for (i = 1; i <= 100005; i++)
   {
      dp[i+1] = max(dp[i+1],dp[i]);
      dp[i+2] = max(dp[i+2],dp[i]+a[i]); 
   }
   cout << dp[100005] << endl;
   return 0;
}