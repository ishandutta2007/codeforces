#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <assert.h>
#include <list>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 131072
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define ALP 26
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,ans,z, K,sx,sy;
string s,t,s1;
ll a[300500];
char c[1005][1005];
ll dp[1005][1005];
ll dir[4][2] = {{1,0}, {0, -1}, {0,1}, {-1, 0}};
string dd = "DLRU";
bool in_range(ll x, ll y)
{
    return (x>=0 && x < n && y >= 0 && y < m);
}
vector<pii> f;
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	time_t t1 = clock();
    cin >> n >> m >> k;
    for (i = 0; i < n; i++)
        scanf("%s", c[i]);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (c[i][j] == 'X')
                sx = i, sy = j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            dp[i][j] = MOD;
    f.push_back(mp(sx, sy));
    dp[sx][sy] = 0;
    i = 0;
    while (i < f.size())
    {
        pii tmp = f[i++];
        for (int j = 0; j < 4; j++)
        {
            int xx = tmp.X + dir[j][0];
            int yy = tmp.Y + dir[j][1];
            if (in_range(xx,yy) && dp[xx][yy] == MOD && c[xx][yy] != '*')
            {
                f.push_back(mp(xx, yy));
                dp[xx][yy] = dp[tmp.X][tmp.Y] + 1;
            }
        }
    }
    if (k%2 == 1 || f.size() == 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < 4; j++)
        {
            int xx = sx + dir[j][0];
            int yy = sy + dir[j][1];
            if (in_range(xx,yy) && dp[xx][yy] <= k-i-1)
            {
                break;
            }
        }
        sx += dir[j][0];
        sy += dir[j][1];
        t.push_back(dd[j]);
    }
    while (clock()-t1 <= 14.995*CLOCKS_PER_SEC){}
    cout << t << endl;
    return 0;
}