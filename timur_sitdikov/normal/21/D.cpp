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
#define pb push_back

const int nmax=16;
const int inf=100000000;
int g[nmax][nmax], st[nmax];
vector<int> bad;
int mm[2][nmax], tp[2];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int ans=0, n, m, a, b, c, i, j, k, f, top, nm, mn, cur;
    cin >> n >> m;
    for(i=1; i<=n; i++)
        for(j=i+1; j<=n; j++)
            g[i][j]=g[j][i]=inf;
    for(i=0; i<m; i++)
    {
        cin >> a >> b >> c;
        ans+=c;
        st[a]++;
        st[b]++;
        g[a][b]=g[b][a]=min(g[a][b], c);
    }
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
    for(i=1; i<=n; i++)
        for(j=i+1; j<=n; j++)
            if (g[i][j]==inf && st[i] && st[j])
            {
                printf("-1");
                return 0;
            }
    if (!st[1] && m)
    {
        printf("-1");
        return 0;
    }
    for(i=1; i<=n; i++)
        if (st[i]&1)
            bad.pb(i);
    top=bad.size();
    f=1;
    for(i=1; i<=top/2; i++)
        f*=i;
    mn=inf;
    for(i=0; i<(1<<(top-1)); i++)
    {
        nm=0;
        for(j=0; j<top; j++)
            if (i&(1<<j))
                nm++;
        if (nm!=top/2)
            continue;
        tp[0]=tp[1]=0;
        for(j=0; j<top; j++)
        {
            if (i&(1<<j))
                mm[1][tp[1]++]=bad[j];
            else mm[0][tp[0]++]=bad[j];
        }       
        for(k=0; k<f; k++)
        {
            cur=0;
            next_permutation(mm[1], mm[1]+top/2);
            for(j=0; j<top/2; j++)
                cur+=g[mm[0][j]][mm[1][j]];
            if (cur<mn) 
                mn=cur;
        }
    }
    if (mn==inf) mn=0;
    ans+=mn;
    printf("%d", ans);
}