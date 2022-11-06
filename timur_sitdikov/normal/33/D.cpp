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
#define point pair<long long, long long>
#define xx first
#define yy second

const int maxn=1005;
char col[maxn];
vector<int> g[maxn], prv[maxn];
int vv[5*maxn], dept[maxn], h[maxn], wh[maxn], fir[maxn], mmn[maxn];
int n, ind, sq, top;
point pt[maxn], pt0, ptt[maxn];
long long rad[maxn];
const int inf=100000000;

double dis(point &pt1, point &pt2)
{
    double tmp=(pt1.xx-pt2.xx)*(pt1.xx-pt2.xx)+(pt1.yy-pt2.yy)*(pt1.yy-pt2.yy);
    return sqrt(tmp);
}

int is_inside(int i, int j)
{
    double ds=dis(pt[i], pt[j]);
    if (rad[j]>rad[i]+ds)
        return 1;
    else
        return 0;
}

void build()
{
    int i;
    sq=(int)(sqrt(top+0.)+0.999999);
    for(i=0; i<sq; i++)
        mmn[i]=inf;
    for(i=0; i<top; i++)
        mmn[i/sq]=min(mmn[i/sq], vv[i]);
}

int find_min(int l, int r)
{
    int pos, rem, ans=vv[l];
    pos=l/sq;
    rem=l%sq;
    while(l<=r)
    {
        if (!rem && l+sq<=r)
        {
            ans=min(ans, mmn[pos]);
            pos++;
            l+=sq;
        }
        else
        {
            ans=min(ans, vv[l]);
            l++;
            rem++;
            if (rem==sq)
            {
                rem=0;
                pos++;
            }
        }
    }
    return ans;
}

void dfs(int s, int dp)
{
    col[s]=1;
    dept[s]=dp;
    fir[s]=top;
    vv[top++]=dp;   
    for(int i=0; i<(int)g[s].size(); i++)
    {
        dfs(g[s][i], dp+1);
        vv[top++]=dp;
    }
}

void go(int s)
{
    for(int i=0; i<(int)g[s].size(); i++)
        if (dis(pt0, pt[g[s][i]])<rad[g[s][i]])
        {
            go(g[s][i]);
            return;
        }
    wh[ind]=s;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j, m, k, mini, a, b, tmp, l, r;
    cin >> m >> n >> k;
    for(i=1; i<=m; i++)
        cin >> ptt[i].xx >> ptt[i].yy;
    for(i=0; i<n; i++)
        cin >> rad[i] >> pt[i].xx >> pt[i].yy;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if (i==j)
                continue;
            if (is_inside(i, j))
            {
                prv[i].pb(j);
                h[i]++;
            }
        }
    for(i=0; i<n; i++)
    {
        if (prv[i].empty())
        {
            g[n].pb(i);
            continue;
        }
        mini=0;
        for(j=1; j<(int)prv[i].size(); j++)
            if (h[prv[i][j]]>h[prv[i][mini]])
                mini=j;
        g[prv[i][mini]].pb(i);
    }
    dfs(n, 0);
    build();
    for(ind=1; ind<=m; ind++)
    {
        pt0=ptt[ind];
        go(n);
    }
    for(i=0; i<k; i++)
    {
        cin >> a >> b;
        l=min(fir[wh[a]], fir[wh[b]]);
        r=max(fir[wh[a]], fir[wh[b]]);
        tmp=find_min(l, r);
        cout << dept[wh[a]]-tmp+dept[wh[b]]-tmp << endl;
    }
}