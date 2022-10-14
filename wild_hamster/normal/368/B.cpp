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
ll i,n,j,k,k1,d,x,m,p,a[200500],b[200500],rez[200500];
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
for (i = 0; i < n; i++)
    cin >> a[i];
ll cnt = 0;
for (i = n - 1; i >= 0; i--)
{
    if (!b[a[i]])
       {
        cnt++;
        b[a[i]] = 1;
       } 
rez[i+1] = cnt;
}
for (i = 0; i < m; i++)
{
    cin >> x;
    cout << rez[x] << endl;
}
return 0;
}