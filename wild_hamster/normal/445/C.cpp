#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll k,j,x,y,n,m,cnt,i,b[600],a[600][600];
vector <vector <ll> > graph(100);
double max1;
int main()
{
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> b[i];
    for (i = 0; i < m; i++)
    {
        cin >> x >> y >> k;
        a[x][y] = a[y][x] = k;
    }
    max1 = 0;
    if (m == 0) printf("%.15f\n",0.);
       else
    {
    for (i = 1; i < n; i++)
        for (j = i+1; j <= n; j++)
        if (a[i][j]!=0)
            max1 = max(max1,((double)(b[i]+b[j])/a[i][j]));
        printf("%.15f\n",max1);    
    }
    return 0;
}