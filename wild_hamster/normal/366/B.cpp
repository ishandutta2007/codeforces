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
ll i,n,j,k,k1,d,x,m,a[100500],b[100500];
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
for (i = 0; i < n; i++)
    cin >> a[i];
ll min1 = (ll)1e+15;
for (i = 0; i < k; i++)
{
    for (j = 0; j < (n-1)/k + 1; j++)
             b[i] += a[i+j*k];
    if (b[i] < min1) min1 = b[i];
}
for (i = 0; i < k; i++)
    if (b[i] == min1)
       {
             cout << i+1 << endl;
             break;
       }
return 0;
}