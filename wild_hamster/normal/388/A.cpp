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
#define N 100500
ll a[1005],b[10005],w,x,y,i,n,m,l,r,j,z,flag,k1,k2,k3,k4;
vector <ll> f[150];
int main()
{
cin >> n;
for (i = 0; i < n; i++)
    cin >> a[i];
sort(a,a+n);
f[0].pb(a[0]);
ll k = 1;
for (j = 1; j < n; j++)
{
 for (i = 0; i < k; i++)
 {   
 z = 0;
 if (f[i].size() <= a[j]) {f[i].pb(0); z = 1; break;}
 }
 if (!z) f[k++].pb(0); 
}   
cout << k << endl;
return 0;
}