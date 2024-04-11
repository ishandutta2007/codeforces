#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
typedef long long ll;
using namespace std;
ll i,j,x,y,a[200][200],n;
int main()
{
   int z = 1;
   cin >> n;
   for (i = 1; i <= n; i++)
   for (j = 1; j <= n; j++)
   {
       char c;
       cin >> c;
       if (c == 'o') a[i][j] = 1;
   }
   for (i = 1; i <= n; i++)
   for (j = 1; j <= n; j++)
    if ((a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1])%2 != 0)
    z = 0;
    if (z) cout << "YES" << endl;
       else cout << "NO" << endl;
    return 0;
}