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
ll max1,i,j,k,x,n,y,lp,rp,p,l,r,ql,qr,m,M_cnt,k1,k2,ost,ur,a[100500],b[100500];
ll Abs(ll a)
{
if (a < 0)
   return -a;
else
    return a;
}
ll sum(ll l, ll r)
{
return b[r] - b[l];
}
int main()
{
cin >> n >> l >> r >> ql >> qr;
b[0] = 0;
for (i = 0; i < n; i++)
{
    cin >> a[i];
        b[i+1] = b[i] + a[i];     
}
ll min1 = (ll)1e+15;
for (i = 0; i <= n; i++)
{
lp = i;
rp = n - i;  
ll s;
if (lp <= rp) 
   s = max((ll)0, rp - lp - 1)*qr;
else
    s = max((ll)0, lp - rp - 1)*ql;
s += l*sum(0,i) + r*sum(i,n);
min1 = min(min1,s);   
}
cout << min1 << endl;
return 0;
}