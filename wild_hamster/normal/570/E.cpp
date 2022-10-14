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
#include <fstream>
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define bull 500400
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,h,x,y;
string s1,s2,s3,s;
ll  dp[3][505][505];
char c[505][505];
int main()
{

    //ios_base::sync_with_stdio(0);
    //printf("%.3f\n",15.5554);
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> c[i][j];
    //dp[pos][first_row][last_row]
    ll pos = (n+m-2)/2;
    if (c[0][0] == c[n-1][m-1])
       dp[0][0][n-1] = 1;
    for (int i = 0; i < pos; i++)
    {
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
            {
                dp[(i+1)&1][j][k] = 0;
                while (dp[i&1][j][k] >= MOD)
                   dp[i&1][j][k] -= MOD;
            }
        for (int first_row = 0; first_row < n; first_row++)
            for (int last_row = 0; last_row < n; last_row++)
            {
                ll first_col = i - first_row;
                ll last_col = m-1-(i-(n-1-last_row));
                j = first_row;
                k = last_row;
                //cout << j << " " << first_col << " " << k << " " << last_col << "     " << i << endl;
                if (first_col < m-1 && last_col > 0 && c[first_row][first_col+1] == c[last_row][last_col-1])
                   dp[(i+1)&1][j][k] = (dp[(i+1)&1][j][k] + dp[i&1][j][k]);
                   
                if (first_col < m-1 && last_row > 0 && c[first_row][first_col+1] == c[last_row-1][last_col])
                   dp[(i+1)&1][j][k-1] = (dp[(i+1)&1][j][k-1] + dp[i&1][j][k]);
                   
                if (first_row < n-1 && last_col > 0 && c[first_row+1][first_col] == c[last_row][last_col-1])
                   dp[(i+1)&1][j+1][k] = (dp[(i+1)&1][j+1][k] + dp[i&1][j][k]);
                   
                if (first_row < n-1 && last_row > 0 && c[first_row+1][first_col] == c[last_row-1][last_col])
                   dp[(i+1)&1][j+1][k-1] = (dp[(i+1)&1][j+1][k-1] + dp[i&1][j][k]);
            }
    }
    ll ans = 0;
    //cout << dp[0][0][0] << endl;
    /*for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << dp[pos&1][i][j] << " ";
        cout << endl;
    }*/
    if ((n+m)%2 == 0)
    {
        for (i = 0; i < n; i++)
            ans += dp[pos&1][i][i];
        ans %= MOD;
        cout << ans << endl;
    } else
    {
        for (i = 0; i < n; i++)
        {
            ll first_col = pos-i;
            if (c[i][first_col] == c[i][first_col+1])
            ans += dp[pos&1][i][i];
        }
        for (i = 0; i < n-1; i++)
        {
            ll first_col = pos-i;
            if (c[i][first_col] == c[i+1][first_col])
            ans += dp[pos&1][i][i+1];
        }
        ans %= MOD;
        cout << ans << endl;
    }
    return 0;
}