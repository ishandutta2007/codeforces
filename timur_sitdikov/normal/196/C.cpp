#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#define point pair<long long, long long>
#define xx first
#define yy second

const int nmax=1505;

point pt[nmax], pt0;
vector<int> g[nmax];

int good[nmax][nmax], top[nmax], col[nmax], sz[nmax], pt_num[nmax], n, ind, ver_num[nmax];

long long dimension(point& pt1, point& pt2, point& pt3)
{return (pt2.xx-pt1.xx)*(pt3.yy-pt1.yy)-(pt3.xx-pt1.xx)*(pt2.yy-pt1.yy);}

bool cmp(int a, int b)
{
    long long d=dimension(pt0, pt[a], pt[b]);
    if (d>0) return true;
    else return false;
}

int dfs1(int s)
{
    int i, ans=0;
    col[s]=1;
    for(i=0; i<(int)g[s].size(); i++)
        if (!col[g[s][i]]) ans+=dfs1(g[s][i]);
    sz[s]=ans+1;
    return ans+1;
}

void dfs(int s)
{
    int i, j, tmp, offset=0;
    pt0=pt[pt_num[s]];
    ind=s;
    sort(good[s], good[s]+top[s], cmp);
    col[s]=1;
    for(i=0; i<(int)g[s].size(); i++)
    {
        tmp=g[s][i];
        if (!col[tmp])
        {
            for(j=0; j<sz[tmp]-1; j++) 
                good[tmp][top[tmp]++]=good[s][offset++];
            pt_num[tmp]=good[s][offset++];
            dfs(tmp);
        }
    }
}

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, a, b, mn;
    scanf("%d", &n);
    for(i=1; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(i=1; i<=n; i++) scanf("%I64d %I64d", &pt[i].xx, &pt[i].yy);
    dfs1(1);
    for(mn=1, i=2; i<=n; i++) if (pt[i]<pt[mn]) mn=i;
    for(i=1; i<=n; i++)
        if (i!=mn) good[1][top[1]++]=i;
    pt_num[1]=mn;
    for(i=1; i<=n; i++) col[i]=0;
    dfs(1);
    for(i=1; i<=n; i++)
        ver_num[pt_num[i]]=i;
    for(i=1; i<=n; i++)
        printf("%d ", ver_num[i]);
}