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
ll max1,i,j,k,x,n,y,lp,rp,p,l,r,ql,qr,m,M_cnt,k1,k2,ost,ur,a[300500],b[100500];
pair <ll,ll> c[10];
int main()
{
ll s = 0;
cin >> n;
for (i = 0; i < n; i++)
    cin >> a[i];
for (i = 0; i < 5; i++)
{
 cin >> c[i].first;
 c[i].second = i;
}
sort(c,c+5);
for (j = 0; j < n; j++)
{
s += a[j];
for (i = 4; i >= 0; i--)
    if (s >= c[i].fi)
       {
             b[ c[i].se ] += s/c[i].fi;
             s %= c[i].fi;
       }
}
for (i = 0; i < 5; i++)
    cout << b[i] << " ";
cout << endl << s << endl;
return 0;
}