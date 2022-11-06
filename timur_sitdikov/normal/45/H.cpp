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
#include <complex>
using namespace std;
#define pb push_back

const int maxn=905;
char g[maxn][maxn], g2[maxn][maxn];
int col[maxn], col2[maxn], good[maxn][2], fup[maxn], tin[maxn], n, top[maxn], repr[maxn], prv[maxn], time;
vector<pair<int, int> > ans, br;

void unite(int i, int j)
{
    if (top[i]==1 && top[j]==1)
        good[i][top[i]++]=good[j][0];
    else if (top[i]==1 && top[j]==2)
    {
        ans.pb(make_pair(repr[good[i][0]], repr[good[j][1]]));
        good[i][0]=good[j][0];
    }
    else if (top[i]==2 && top[j]==1)
    {
        ans.pb(make_pair(repr[good[i][1]], repr[good[j][0]]));
        top[i]--;
    }
    else if (top[i]==2 && top[j]==2)
    {
        ans.pb(make_pair(repr[good[i][1]], repr[good[j][1]]));
        good[i][1]=good[j][0];
    }
    else
    {
        top[i]=top[j];
        for(int k=0; k<top[i]; k++)
            good[i][k]=good[j][k];
    }
}

void dfs(int s)
{
    col[s]=1;
    tin[s]=fup[s]=++time;

    for(int i=1; i<=n; i++)
        if (g[s][i])
        {
            if (!col[i])
            {
                prv[i]=s;
                dfs(i);
                if (fup[i]>tin[s])
                {
                    g[s][i]=g[i][s]=0;
                    br.pb(make_pair(s, i));
                }
                fup[s]=min(fup[s], fup[i]);
            }
            else if (i!=prv[s])
            {
                fup[s]=min(fup[s], tin[i]);
            }
        }
}

void dfs1(int s, int cl)
{
    col2[s]=cl;
    for(int i=1; i<=n; i++)
        if (g[s][i] && !col2[i])
            dfs1(i, cl);
}

void dfs2(int s)
{
    col[s]=1;
    int i, f=0;
    for(i=1; i<=n; i++)
        if (g2[s][i] && !col[i])
        {
            dfs2(i);
            unite(s, i);
            f=1;
        }
    if (!f)
        good[s][top[s]++]=s;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int m, a, b, i, j, cl, st1, f, bad;
    cin >> n >> m;
    if (n==2)
    {
        printf("-1");
        return 0;
    }
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        g[a][b]=g[b][a]=1;
    }
    dfs(1);
    cl=0;
    for(i=1; i<=n; i++)
        if (!col2[i])
        {
            dfs1(i, ++cl);
            repr[cl]=i;
        }
    for(i=0; i<(int)br.size(); i++)
        g2[col2[br[i].first]][col2[br[i].second]]=g2[col2[br[i].second]][col2[br[i].first]]=1;
    for(i=1; i<=n; i++)
        col[i]=0;
    dfs2(1);
    for(i=0; i<(int)br.size(); i++)
        g[br[i].first][br[i].second]=g[br[i].second][br[i].first]=1;
    if (top[1]==2)
    {
        ans.pb(make_pair(repr[good[1][0]], repr[good[1][1]]));
        top[1]-=2;
    }
    st1=0;
    for(i=2; i<=n; i++)
        st1+=g2[1][i];
    bad=0;
    if (st1==1 && top[1]==1)
    {
        f=0;
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if (!f && col2[i]==col2[1] && col2[j]==col2[repr[good[1][0]]] && !g[i][j])
                {
                    ans.pb(make_pair(i, j));
                    f=1;
                }
    }
    else 
    {       
        if (st1==1)
            bad=1;
        else if (top[1]==1)
            bad=repr[good[1][0]];
    }
    if (bad)
    {
        f=0;
        for(i=1; i<=n; i++)
            if (!f && !g[i][bad] && col2[i] !=col2[bad])
            {
                f=1;
                ans.pb(make_pair(i, bad));
            }
    }
    for(st1=0, i=2; i<=n; i++)
        st1+=g2[1][i];
    cout << ans.size() << endl;
    for(i=0; i<(int)ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;
}