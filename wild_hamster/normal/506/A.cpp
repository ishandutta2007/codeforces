#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
string s;
ll dif,n,i,j,k1,k2,k3,d,x,k,y,m,l,r,c,t,sum,a[100500],dp[30500][605];

int main()
{
    cin >> n >> d;
    for (i = 0; i <= 30000; i++)
        for (j = 0; j <= 600; j++)
            dp[i][j] = -(ll)1e+18;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        a[x]++;
    }
    l = max(d-300,1LL);
    dif = l-1;    
    dp[d][d-dif] = a[d];
   // cout << d-dif << endl;
    for (i = d; i < 30000; i++)
        for (j = 1; j <= 600; j++)
        if (dp[i][j] >= 0)
        {
            if (i+(j-1+dif) <= 30000)
            dp[i+(j-1+dif)][j-1] = max(dp[i+(j-1+dif)][j-1],dp[i][j]+a[i+(j-1+dif)]);
            if (i+(j+dif) <= 30000)
            dp[i+(j+dif)][j] = max(dp[i+(j+dif)][j],dp[i][j]+a[i+(j+dif)]);
            if (i+(j+1+dif) <= 30000)
            dp[i+(j+1+dif)][j+1] = max(dp[i+(j+1+dif)][j+1],dp[i][j]+a[i+(j+1+dif)]);
        }
    ll rez = 0;
    for (i = 0; i <= 30000; i++)
        for (j = 1; j <= 600; j++)
        {
            ///if (dp[i][j] == 0)
            //   cout << i << " " << j << endl;
            rez = max(rez,dp[i][j]);
        }
    cout << rez << endl;
    //system("pause");
    return 0;
}