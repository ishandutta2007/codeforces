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
ll a[100500][10],b[500500],used[1000500],x,y,i,j,n,m,k,q,max1,min1;
vector <ll> f,g,rez;
int main()
{
string s1,s2;
cin >> n >> m;
for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
        scanf("%d",&a[i][j]);
for (i = 1; i < n; i++)
    a[i][0] += a[i-1][0];
for (i = 0; i < n; i++)
    for (j = 1; j < m; j++)
        if (!i) a[i][j] += a[i][j-1];
           else a[i][j] += max(a[i-1][j],a[i][j-1]);
/*for (i = 0; i < n; i++)
{
    cout << endl;
    for (j = 0; j < m; j++)
        cout << a[i][j] << " ";
}*/
for (i = 0; i < n; i++)
    printf("%d ",a[i][m-1]);
return 0;
}