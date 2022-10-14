#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <set>
//#include <cmath>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 100500
#define eps 1e-9
ll c[15000],b[1005][1005],sum,x,y,i,j,n,m,k,j1,r1,r2,min1;
pair <ll,ll> a[20000];
string s, s1;
int main()
{
    ll rez = 0;
cin >> n >> m;
for (i = 0; i < n; i++)
{
    cin >> a[i].fi;
    c[i] = a[i].fi;
    a[i].se = i;
}
sort(a,a+n);
for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--; y--;
        b[x][y] = 1;
        b[y][x] = 1; 
    }
for (i = n-1; i >= 0; i--)
{
    for (j = 0; j < n; j++)
        if (b[j][a[i].se] == 1)
        {
           rez += c[j];
           b[j][a[i].se] = 0;
           b[a[i].se][j] = 0;          
        }
}
cout << rez << endl;
return 0;
}