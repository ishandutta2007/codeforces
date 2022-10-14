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
ll rez,i,n,j,k,k1,d,x,m,p,a[200500];
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
ll min1 = (ll)1e+17;
ll cnt = 0, point = 0;
for (i = 0; i < n; i++)
{
    if (i < d - 1) cnt += a[i];
    else
        {
            cnt += a[i];
            if (cnt < min1)
            {
                    min1 = cnt;
                    point = i;
            }
            cnt -= a[i-d+1];
        }
}
cout << point + 2 - d << endl;
return 0;
}