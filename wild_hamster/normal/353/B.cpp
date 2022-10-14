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
ll sum,max1,i,j,k[500],x,n,y,m,k1,k2,ost,ur,a[100500],c1[500],c2[500],pos,b[5][100];
int main()
{
string s;
cin >> n;
m = 0; 
for (i = 0; i < 2*n; i++)
{
    cin >> a[i];
    k[ a[i] ] ++;
}
ll cnt = 0;
for (i = 10; i <= 99; i++)
    if (k[i] == 1)
       {
        k[i]--;
        b[cnt][i]++;
        cnt = (cnt+1) % 2;
        if (k[i] == 0) m++;
       }
for (i = 10; i <= 99; i++)
    if (k[i] % 2)
       {
        k[i]--;
        b[cnt][i]++;
        cnt = (cnt+1) % 2;
       }
if (m%2 == 0) x = 1;
m /= 2;
//cout << m << endl;
for (i = 10; i <= 99; i++)
{
if (k[i] > 0) m++;
    for (j = 0; j < 2; j++)
        b[j][i] += k[i]/2;
}
if (x) cout << m*m << endl;
   else cout << m*(m+1) << endl;
for (i = 0; i < 2*n; i++)
    if (b[0][ a[i] ])
       {
              b[0][ a[i] ] --;
              cout << 1 << " "; 
       }
    else
        cout << 2 << " ";


return 0;
}