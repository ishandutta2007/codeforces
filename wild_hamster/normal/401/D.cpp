#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
typedef long long ll;
using namespace std;
ll i,j,n,rez,k,m,y,z,x,a[100],dp[100][300000][2],x10[25],used[15];
string s;
bool lalka(ll x, ll y)
{
 ll rez = 0;
 for (int i = 0; i < n; i++)
     if (x&(1<<i))
        rez++;
 if (rez == y) return true;
 return false;
}
int main()
{
    cin >> s;
    cin >> m;
    n = s.size();
    x10[0] = 1;
    for (i = 0; i < n; i++)
        a[i] = s[i] - '0';
    for (i = 1; i < 18; i++)
        x10[i] = x10[i-1]*10;
    for (j = 0; j < n; j++)
        if (a[j]!=0 && !used[a[j]])
        {
           dp[(x10[n-1]*a[j])%m][1<<j][0]++;
           used[a[j]] = 1;
        }
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < (1<<n); j++)
        if (lalka(j,i+1))
        {
            //cout << j << endl;
            for (k = 0; k < 10; k++)
                used[k] = 0;
            for (k = 0; k < n; k++)
            if (((1<<k)&j) == 0&&!used[a[k]])
            {
            //cout << k << " " << a[k] << endl;
             used[a[k]] = 1;
             for (x = 0; x < m; x++)
             {
                 //cout << dp[x][j][i%2] << " " << j << endl;              
                 dp[(x+x10[n-i-2]*a[k])%m][j|(1<<k)][(i+1)%2]+=dp[x][j][i%2];
             }
            }
        }
    }
    cout << dp[0][(1<<n)-1][(n-1)%2] << endl;
    return 0;
}