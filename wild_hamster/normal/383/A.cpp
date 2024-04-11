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
#define N 2001
vector <ll> lal;
ll a[1005000],b[1000500],c[1000500],used[4242424],w,x,i,n,m,j,flag;
vector < pair<ll,ll> > f;
int main()
{
cin >> n;
for (i = 0; i < n; i++)
    cin >> a[i];
b[n] = 0;
ll k1 = 0, k2 = 0;
for (i = n-1; i >= 0; i--)
    b[i] = b[i+1] + (1 - a[i]);
for (i = 0; i < n; i++)
    if (a[i])
       k1 += b[i];
for (i = 0; i < n; i++)
if (i)
    c[i] = c[i-1] + a[i];
else
    c[i] = a[i];
for (i = 0; i < n; i++)
    if (!a[i])
       k2 += c[i];
cout << min(k1,k2) << endl;
return 0;
}