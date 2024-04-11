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
vector <ll> azaza;
ll rez,i,n,j,k,k1,k2,l,r,d,sall,sk,x,m,p,a[550000];
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
map <ll,ll> f;
int main()
{
cin >> n;
for (i = 0; i < n; i++)
    scanf("%d",&a[i]);
sort(a,a+n);
ll rez = n;
l = 0; r = n/2;
while (r < n)
{
 while (a[l]*2 > a[r] && r < n) r++;
 if (r < n)
    {
         rez--;
         l++;
         r++;
    }
}
cout << max(rez, n - n/2) << endl;
return 0;
}