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
ll rez,i,n,j,k,k1,d,x,m,p,a[200500],b[200500],c[30],f[1050000];
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
cin >> n >> m >> d;
for (i = 1; i <= m; i++)
{
    cin >> x;
    for (j = 0; j < x; j++)
    {
       cin >> k;
       a[k-1] = i; 
    }
}

for (i = 0; i < d; i++)
    c[a[i]]++;
ll l = 0, r = d;
ll tmp = 0;
for (i = 1; i <= m; i++)
   if (c[i] == 0) tmp = (tmp|(1<<(i-1))); 
f[tmp] = 1;
for (r = r; r < n; r++, l++)
    {
         c[a[r]]++;
         c[a[l]]--;
    tmp = 0;
    for (i = 1; i <= m; i++)
        if (c[i] == 0) tmp = (tmp|(1<<(i-1))); 
    f[tmp] = 1;
    }
rez = m;
for (i = (1<<m)-1; i >= 0; i--)
    if (f[i])
    {
       for (j = 0; j < m; j++)
           if (i&(1<<j)) f[i^(1<<j)] = 1;
    }
    else
    {
        ll tmp = 0;
        for (j = 0; j < m; j++)
            if ((1<<j)&i) tmp++;
        rez = min(rez, tmp); 
    }
cout << rez << endl;
return 0;
}