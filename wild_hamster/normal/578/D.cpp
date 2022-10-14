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
#define INF ((ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,l,r,z;
string s1,s2,s3,s,t;
ll dp[100500][10];
int main()
{
    cin >> n >> m;
    cin >> s;
    for (i = 0; i < n; i++)
        s[i] -= 'a';
    s.push_back('U');
    if (s[0] != s[1])
       dp[1][4] = m-2;
    else
        dp[1][4] = m-1;
    dp[1][7] = 1;
    if (s[0] != s[1])
       dp[1][5] = 1;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < 8; j++)
        {
            for (k = 0; k < m; k++)
            {
             ll fb = ((j>>2)&1), sb = ((j>>1)&1), tb = (j&1);
             ll ffb,ssb,ttb;
             if (i-1>= 0 && s[i-1] == k)
                ffb = fb;
             else
                 ffb = sb;
             if (s[i] == k)
                ssb = sb;
             else
                 ssb = max(ffb-1,tb-1);
             if (s[i+1] == k)
                tb = tb;
             else
                 tb = ssb;
             if (ffb >= 0 && ssb >= 0 && tb >= 0)
             dp[i+1][ffb*4+ssb*2+tb] += dp[i][j];
            }
        }
    }
    /*for (i = 1; i <= n; i++)
    {
        for (j = 0; j < 8; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }*/
    cout << dp[n][0] + dp[n][1] + dp[n][4] + dp[n][5] << endl;
    return 0;
}