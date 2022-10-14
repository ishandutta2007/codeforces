#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll i,j,x,n,m,k,k1,k2,ost,ur,a[100500],b[1300500],pos;
vector <ll> f[100500];
map <ll,ll> g;
int main()
{
cin >> n;
for (i = 0; i < n; i++)
     cin >> a[i];
f[0].pb(a[0]);
for (i = 1; i < n; i++)
    {
         f[i].pb(a[i]);
         g[ 1300005*i+a[i] ] = 1;
         for (j = 0; j < f[i-1].size(); j++)
         {
         b[ f[i-1][j] ] = 1;
             if (g[ 1300005*i + (f[i-1][j] | a[i]) ] == 0)
                {
                    g[ 1300005*i +  (f[i-1][j] | a[i]) ] = 1;
                    f[i].pb(f[i-1][j] | a[i]);
                }
         }
    }
for (j = 0; j < f[n-1].size(); j++)
b[ f[n-1][j] ] = 1;
for (i = 0; i < 1300050; i++)
    if (b[i])
       k++;
cout << k << endl;
return 0;
}