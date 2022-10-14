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
ll i,j,x,n,y,m,k,k1,k2,ost,ur,a[1005],b[1300],pos;
int main()
{
cin >> n >> m;
for (i = 0; i < n; i++)
    cin >> a[i];
for (i = 0; i < m; i++)
    cin >> b[i];
ll rez = 0;
for (rez = 0; rez < 500; rez++)
    {
         int flag = 1, x = 0;
         for (i = 0; i < n; i++)
             if (a[i] > rez)
                flag = 0;
             else
                 if (a[i] * 2 <= rez) 
                    x++;
         if (x == 0) 
            flag = 0;
         for (i = 0; i < m; i++)
             if (b[i] <= rez)
                flag = 0;
         if (flag) 
         {
         ost = 57;         
         break;
         }
    }
if (ost == 57) 
   cout << rez << endl;
else cout << -1 << endl; 
return 0;
}