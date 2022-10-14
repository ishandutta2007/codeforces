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
map <ll,ll> be;
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
cin >> n >> m;
for (i = 0; i < m; i++)
    {
    cin >> a[i];
    be[a[i]] = 1;
    }
sort(a,a+m);
bool z = true;
if (a[0] == 1 || a[m-1] == n) z = false;
for (i = 0; i < m; i++)
    if (be[a[i]+1] && be[a[i]+2]) z = false;
if (z) cout << "YES" << endl;
   else cout << "NO" << endl;
    
return 0;
}