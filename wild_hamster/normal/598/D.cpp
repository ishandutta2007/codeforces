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
#define MOD 100003
#define MOD2 (33LL+(ll)1e+17)
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 118228
typedef int ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag,timer,start,finita,ans;
ll a[1005][1005],used[1005][1005];
vector <pair<double,ll> > angles;
ll direction[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
string s;
void dfs(ll x, ll y)
{
    used[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (a[x+direction[i][0]][y+direction[i][1]] == -1)
           k1++;
    if (!used[x+direction[i][0]][y+direction[i][1]] && a[x+direction[i][0]][y+direction[i][1]] == 0)
       dfs(x+direction[i][0],y+direction[i][1]);
    }
}
void dfs2(ll x, ll y)
{
    a[x][y] = k1;
    for (int i = 0; i < 4; i++)
    {
    if (a[x+direction[i][0]][y+direction[i][1]] == 0)
       dfs2(x+direction[i][0],y+direction[i][1]);
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m >> k;
    for (i = 0; i <= n+1; i++)
        for (j = 0; j <= m+1; j++)
            a[i][j] = -1;
    for (i = 1; i <= n; i++)
    {
        char s[1005];
        scanf("%s",s);
        for (j = 0; j < m; j++)
            if (s[j] != '*')
               a[i][j+1] = 0;
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i][j] == 0)
            {
                k1 = 0;
                dfs(i,j);
                dfs2(i,j);
            }
    for (i = 0; i < k; i++)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",a[x][y]);
    }
    return 0;
}