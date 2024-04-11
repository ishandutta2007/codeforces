#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll a[1005][1005],kozel[1005][1005],koza[1005][1005],z,cnt,tmp,l,r,n,m,x,y,k,j,p,k1,k2,i,cur;
ll kozelrev[1005][1005],kozarev[1005][1005],rez;
string s,s1,s2;
ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
}

int main()
{
   cin >> n >> m;
   for (i = 1; i <= n; i++)
       for (j = 1; j <= m; j++)
           cin >> a[i][j];
   for (i = 1; i <= n; i++)
       for (j = 1; j <= m; j++)
           kozel[i][j] = max(a[i][j]+kozel[i-1][j],a[i][j]+kozel[i][j-1]);
   for (i = 1; i <= n; i++)
       for (j = m; j >= 1; j--)
           koza[i][j] = max(a[i][j]+koza[i-1][j],a[i][j]+koza[i][j+1]);
   for (i = n; i >= 1; i--)
       for (j = m; j >= 1; j--)
           kozelrev[i][j] = max(a[i][j]+kozelrev[i+1][j],a[i][j]+kozelrev[i][j+1]);
   for (i = n; i >= 1; i--)
       for (j = 1; j <= m; j++)
           kozarev[i][j] = max(a[i][j]+kozarev[i+1][j],a[i][j]+kozarev[i][j-1]);
   for (x = 2; x <= n-1; x++)
       for (y = 2; y <= m-1; y++)
       {
           tmp = max(kozel[x][y-1]+kozelrev[x][y+1]+koza[x-1][y]+kozarev[x+1][y],
           kozel[x-1][y]+kozelrev[x+1][y]+koza[x][y+1]+kozarev[x][y-1]);
           rez = max(rez,tmp);
       }
  /* for (i = 1; i <= n; i++)
   {
       for (j = 1; j <= m; j++)
           cout << kozel[i][j] << " ";
       cout << endl;
   }
   for (i = 1; i <= n; i++)
   {
       for (j = 1; j <= m; j++)
           cout << koza[i][j] << " ";
       cout << endl;
   }
   for (i = 1; i <= n; i++)
   {
       for (j = 1; j <= m; j++)
           cout << kozelrev[i][j] << " ";
       cout << endl;
   }
   for (i = 1; i <= n; i++)
   {
       for (j = 1; j <= m; j++)
           cout << kozarev[i][j] << " ";
       cout << endl;
   }*/
   cout << rez << endl;
   return 0;
}