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
ll max1,i,j,x,n,y,m,k,k1,k2,ost,ur,marked[100500],b[400][400],a[100500],used[100500],pos;
vector <pair <ll,ll> > f,g;
int main()
{
cin >> n >> m >> k;
for (i = 0; i < k; i++)
{
    cin >> k1;
    a[i] = k1;
    marked[k1]=1;
}
for (i = 1; i <= n; i++)
if (!marked[i])
   {
   for (j = 1 ; j <= n; j++)
       if (i != j && !b[i][j])
          {
              f.pb(mp(i,j));
              b[i][j]=1;
              b[j][i]=1;
          }
   }  
for (i = 1; i < k; i++)
    for (j = 1; j < k; j++)
    if (i != j && !b[a[i]][a[j]])
          {
              f.pb(mp(a[i],a[j]));   
              b[a[i]][a[j]]=1;
              b[a[j]][a[i]]=1;
          }
           
if (m > f.size() || n == k)
   cout << -1 << endl;
else
for (i = 0; i < m; i++)
    cout << f[i].fi << " " << f[i].se << endl;
return 0;
}