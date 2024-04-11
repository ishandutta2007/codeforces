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
ll rez,i,n,j,k,k1,k2,l,r,d,sall,sk,x,m,p,a[200500];
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
cin >> n >> k >> l >> r >> sall >> sk;
vector <ll> f;
ll tmp = sall - sk;
for (i = 0; i < k; i++)
    {
     f.pb(sk/(k-i));
     sk -= sk/(k-i);
    }
for (i = 0; i < n-k; i++)
    {
     f.pb(tmp/(n-k-i));
     tmp -= tmp/(n-k-i);
    }
for (i = 0; i < f.size(); i++)
    cout << f[i] << " ";    
return 0;
}