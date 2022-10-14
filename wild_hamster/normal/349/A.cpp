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
ll i,j,x,n,m,k,k1,k2,a[100500];
int main()
{
cin >> n;
ll z = 0;
for (i = 0; i < n; i++)
    {
     cin >> k;
     if (k == 25) a[k]++;
     if (k == 50) 
        {
         a[25]--;
         a[50]++;
        }
     if (k == 100) 
        if (a[50] > 0) 
           {
                  a[50]--;
                  a[25]--;
           }
        else
            a[25] -= 3;
    if (a[25] < 0 || a[50] < 0) z=1;
    }
if (!z) 
   cout << "YES" << endl; 
else
   cout << "NO" << endl; 
return 0;
}