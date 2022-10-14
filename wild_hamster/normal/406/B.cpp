#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <set>
#include <cmath>
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
ll a[1000500],b[500500],used[1000500],x,y,i,j,n,m,k,q;
vector <ll> f,g,rez;
int main()
{
cin >> n;
for (i = 0; i < n; i++)
{
    scanf("%d",&k);
    a[k] = 1;
    f.pb(k);
}
for (i = 1; i <= 500000; i++)
    if (a[i] == 0 && a[1000001 - i] == 0)
       g.pb(i);
j = 0;
for (i = 0; i < f.size(); i++)
{
    if (!used[f[i]])
    {
       if (a[1000001-f[i]] == 1)
           {
            used[1000001-f[i]] = 1;
            rez.pb(g[j]);rez.pb(1000001-g[j]);
            j++;
           }
       else
           rez.pb(1000001 - f[i]);
    }
}
cout << rez.size() << endl;
for (i = 0; i < rez.size(); i++)
    printf("%d ",rez[i]);
return 0;
}