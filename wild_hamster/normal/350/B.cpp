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
ll max1,i,j,x,n,y,m,k,k1,k2,ost,ur,a[100500],b[100500],c[100500],used[100500],pos;
vector <ll> f,g;
void dfs(ll x)
{
     f.pb(x);
     if (!used[ b[x] ] && b[x]!=0) dfs(b[x]);
     else 
      if (f.size()>max1)
         {
          max1=f.size();
          g=f;
         }
}
int main()
{
max1 = -1;
cin >> n;
for (i = 1; i <= n; i++)
    cin >> a[i];
for (i = 1; i <= n; i++)
    {
     cin >> b[i];
     if (b[i] == 0) f.pb(i);
     if (c[ b[i] ] != 0) used[ b[i] ] = 1;
     else c[ b[i] ] = i;
    }
for (i = 1; i <= n; i++)
    if (a[i] == 1)
    {
       f.clear();
       dfs(i);
    }
cout << g.size() << endl;
for (i = 0; i < g.size(); i++)
    cout << g[g.size()-i-1] << " ";
return 0;
}