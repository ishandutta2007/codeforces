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
typedef int ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,h,x,y;
string s1,s2,s3,s;
ll level[500500],b[105];
vector<ll> g[500500],f[500500];
string t[500500];
vector <ll> part[500500];
ll in[500500], out[500500], pos[500500];
ll timer;
void dfs(int v)
{
    in[v] = ++timer;
    for (int i = 0; i < g[v].size(); i++)
        dfs(g[v][i]);
    out[v] = timer;
}
int main()
{
    timer = 0;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //printf("%.3f\n",15.5554);
    cin >> n >> m;
    for (i = 0; i < n-1; i++)
    {
        scanf("%d",&x);
        g[x].push_back(i+2);
    }
    cin >> s;
    f[1].push_back(1);
    t[1].push_back(s[0]);
    pos[1] = 0;
    j = 1;
    while (f[j].size() != 0)
    {
        for (i = 0; i < f[j].size(); i++)
        {
            ll v = f[j][i];
            level[v] = j;
            pos[v] = i;
            for (k = 0; k < g[v].size(); k++)
            {
                f[j+1].push_back(g[v][k]);
                t[j+1].push_back(s[g[v][k]-1]);
            }
        }
        j++;
    }
    dfs(1);
    ll k = j;
    for (i = 1; i < k; i++)
    {
        ll sz = t[i].size();
            part[i].resize(sz+1);
        part[i][0] = 0;
        for (j = 0; j < f[i].size(); j++)
        {
            part[i][j+1] = part[i][j];
            part[i][j+1] ^= (1<<(t[i][j]-'a'));
        }
    }
    for (i = 0; i < m; i++)
    {
        ll v,h;
        scanf("%d %d",&v,&h);
        if (level[v] >= h)
        {
           printf("Yes\n");
           continue;
        }
        ll dif = h - level[v];
        ll lft = v, rgt = v;
        ll l = 0, r = f[h].size();
        //cout << t[h] << endl;
        r--;
        if (l > r)
        {
            printf("Yes\n");
            continue;
        }
        ll lb = in[v], rb = out[v];
        //cout << lb << " " << rb << " " << out[f[h][0]] << " " << out[f[h][1]] << endl;
        if (out[f[h][r]] < lb)
           l = f[h].size();
        else
        {
         ll l1 = l, r1 = r;
         while (l1 < r1)
         {
            ll mid = (l1+r1-1)/2;
            if (out[f[h][mid]] >= lb)
               r1 = mid;
             else
                 l1 = mid+1;
         }
         l = l1;
        }
        if (out[f[h][0]] > rb)
           r = -1;
        else
        {
         ll l1 = 0, r1 = f[h].size()-1;
         while (l1 < r1)
         {
            ll mid = (l1+r1+1)/2;
            if (out[f[h][mid]] <= rb)
               l1 = mid;
             else
                 r1 = mid-1;
         }
         r = r1;
        }
        if (l > r)
        {
            printf("Yes\n");
            continue;
        }
        //cout << l << " " << r << endl;
        ll sum = 0;
        ll tmp = (part[h][r+1]^part[h][l]);
        for (j = 0; j <= 25; j++)
            if ((tmp&(1<<j)) != 0)
               sum++;
        //cout << tmp << " " << sum << endl;
        if (sum > 1)
           printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}