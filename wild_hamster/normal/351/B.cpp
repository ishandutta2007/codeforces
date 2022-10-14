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
ll sum,max1,i,j,k,x,n,y,m,k1,k2,ost,ur,a[100500],a1[5000],a2[5000],used[100500],pos;
int main()
{
string s;
k = 0;
cin >> n;
for (i = 0; i < n; i++)
    cin >> a[i];
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        if (a[j-1] > a[j]) 
           {
           k++;
           swap(a[j],a[j-1]);
           //for (k1 = 0; k1 < n; k1++)
           //    cout << a[k1] << " ";
           //cout << endl;
           }
x = (n*(n-1))/2;
//cout << k << endl;
if (k%2 == 0)
   cout << 2*k << endl;
else
    cout << 2*k - 1 << endl;
return 0;
}