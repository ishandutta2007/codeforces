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
ll i,j,x,n,m,k,k1,k2,ost,ur,a[100500],pos;
int main()
{
cin >> n;
ll min1 = 100500;
for (i = 0; i < 9; i++)
    {
     cin >> a[i];
     if (a[i] <= min1) 
     {
      min1 = a[i];
      pos = i;
     }
    }
ost = n % a[pos];
ur = n / a[pos];
k = 8;
while (1)
  {
  k2 = 15;
  for (i = 8; i > pos; i--)
        if (a[i] - min1 <= ost)
        {
              k2 = i;
              break;
        } 
  if (k2 == 15) break;
  k1 = min(ost / (a[k2] - min1),n / a[pos]);
  for (i = 0; i < k1; i++)
      cout << k2+1;
  ost -= k1 * (a[k2] - min1);
  ur -= k1;
  }
if (k1 == 0 && ur == 0) 
   {
    cout << -1 << endl;
    return 0;
   }
for (i = 0; i < ur; i++)
    cout << pos + 1;
return 0;
}