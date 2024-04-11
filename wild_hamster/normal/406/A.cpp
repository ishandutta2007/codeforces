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
ll a[1005][1005],x,y,i,j,n,m,k,q,rez;
int main()
{
cin >> n;
rez = 0;
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
        scanf("%d",&a[i][j]);
        if (i == j) rez += a[i][j];
    }
rez %= 2;
cin >> q;
for (i = 0; i < q; i++)
{
    scanf("%d",&k);
    if (k == 3) 
     printf("%d",rez);
       else
       { 
         scanf("%d",&x);   
         rez = (rez+1) % 2;
       }
}
return 0;
}