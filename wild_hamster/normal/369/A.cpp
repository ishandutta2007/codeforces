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
vector <ll> azaza;
ll rez,i,n,j,k,k1,k2,d,x,m,p,a[200500];
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
cin >> n >> m >> k;
for (i = 0; i < n; i++)
{
    cin >> a[i];
    if (a[i] == 1) k1++;
       else k2++;
}
if (k1 >= m)
   cout << k1 - m + max((ll)0, k2 - k) << endl;
else
    cout << max((ll)0,k1 + k2 - m - k) << endl;
return 0;
}