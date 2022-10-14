#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <set>
//#include <cmath>
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
ll dp[2005][2005],used[5000],sum,x,y,i,j,n,m,k,q,j1,max1,min1;
vector <pair<ll,ll> > f;

int main()
{
for (i = 1; i <= 2000; i++)
    dp[i][1] = 1;
for (j = 1; j <= 2000; j++)
    for (i = 1; i <= 2000; i++)
        for (k = i; k <= 2000; k += i)
            dp[k][j+1] = (dp[k][j+1] + dp[i][j])%tr;
cin >> n >> k;
for (i = 1; i <= n; i++)
    sum = (sum + dp[i][k])%tr;
cout << sum << endl;
return 0;
}