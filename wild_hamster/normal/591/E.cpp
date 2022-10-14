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
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 (33LL+(ll)1e+17)
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define MAXN 100100
typedef long long ll;
using namespace std;
ll x,y,l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,z,max1,tx,pnt,flag;
vector <ll> divisors,ans;
ll min_path[5][5];
string s;
ll a[105];
char c[1005][1005];
ll d1[1005][1005],d2[1005][1005],d3[1005][1005],used[1005][1005];
vector <pair<ll,ll> > f;
int main()
{
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            cin >> c[i][j];
    for (i = 0; i <= n+1; i++)
        for (j = 0; j <= m+1; j++)
            used[i][j] = 1;
            
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            used[i][j] = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (c[i][j] == '1')
            {
                f.push_back(mp(i,j));
                used[i][j] = 1;
                d1[i][j] = 0;
            } else
            d1[i][j] = INF;
            if (c[i][j] == '#')
               used[i][j] = 1;
        }
    i = 0;
    while (i < f.size())
    {
        ll x = f[i].first;
        ll y = f[i].second;
        i++;
        ll pos[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
        for (j = 0; j < 4; j++)
        if (!used[x+pos[j][0]][y+pos[j][1]])
        {
            used[x+pos[j][0]][y+pos[j][1]] = 1;
            d1[x+pos[j][0]][y+pos[j][1]] = d1[x][y] + 1;
            f.push_back(mp(x+pos[j][0],y+pos[j][1]));
        }
    }
    f.clear();
    
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            used[i][j] = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (c[i][j] == '2')
            {
                f.push_back(mp(i,j));
                used[i][j] = 1;
                d2[i][j] = 0;
            } else
            d2[i][j] = INF;
            if (c[i][j] == '#')
               used[i][j] = 1;
        }
    i = 0;
    while (i < f.size())
    {
        ll x = f[i].first;
        ll y = f[i].second;
        i++;
        ll pos[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
        for (j = 0; j < 4; j++)
        if (!used[x+pos[j][0]][y+pos[j][1]])
        {
            used[x+pos[j][0]][y+pos[j][1]] = 1;
            d2[x+pos[j][0]][y+pos[j][1]] = d2[x][y] + 1;
            f.push_back(mp(x+pos[j][0],y+pos[j][1]));
        }
    }
    f.clear();
    
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            used[i][j] = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (c[i][j] == '3')
            {
                f.push_back(mp(i,j));
                used[i][j] = 1;
                d3[i][j] = 0;
            } else
            d3[i][j] = INF;
            if (c[i][j] == '#')
               used[i][j] = 1;
        }
    i = 0;
    while (i < f.size())
    {
        ll x = f[i].first;
        ll y = f[i].second;
        i++;
        ll pos[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
        for (j = 0; j < 4; j++)
        if (!used[x+pos[j][0]][y+pos[j][1]])
        {
            used[x+pos[j][0]][y+pos[j][1]] = 1;
            d3[x+pos[j][0]][y+pos[j][1]] = d3[x][y] + 1;
            f.push_back(mp(x+pos[j][0],y+pos[j][1]));
        }
    }
    f.clear();
    min_path[1][2] = min_path[1][3] = min_path[2][3] = INF;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (c[i][j] == '1')
            {
                min_path[1][3] = min(min_path[1][3],d3[i][j]);
                min_path[1][2] = min(min_path[1][2],d2[i][j]);
            }
            if (c[i][j] == '2')
            {
                min_path[2][3] = min(min_path[2][3],d3[i][j]);
                min_path[1][2] = min(min_path[1][2],d1[i][j]);
            }
            if (c[i][j] == '3')
            {
                min_path[1][3] = min(min_path[1][3],d1[i][j]);
                min_path[2][3] = min(min_path[2][3],d2[i][j]);
            }
        }
    ll ans = INF;
    //cout << min_path[1][2] << " " << min_path[1][3] << " " << min_path[2][3] << endl;
    ans = min(ans,min_path[1][2] + min_path[2][3]);
    ans = min(ans,min_path[1][3] + min_path[2][3]);
    ans = min(ans,min_path[1][2] + min_path[1][3]);
    ans -= 2;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            ans = min(ans,d1[i][j]+d2[i][j]+d3[i][j]-2);
    if (ans > 1005000)
       cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}