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
#define mp make_pair
#define point complex<double>
#define tr pair<pair<int, int>, int>
#define pii pair<int, int>
#define xx first
#define yy second

const int maxn=3005, inf=1000000000;
char g[maxn][maxn];
int dis[maxn][maxn], prv[maxn][maxn], n;
queue<pii> qq;
set<tr> st;
vector<int> ans;

void bfs()
{
    int i, j, k;
    for(i=1; i<=n; i++)
        for(j=i+1; j<=n; j++)
            dis[i][j]=dis[j][i]=inf;
    for(k=1; k<=n; k++)
        if (g[1][k])
        {
            dis[1][k]=1;
            qq.push(mp(1, k));
        }
    while(!qq.empty())
    {
        i=qq.front().xx;
        j=qq.front().yy;
        qq.pop();
        for(k=1; k<=n; k++)
            if (g[j][k] && dis[j][k]==inf && st.find(mp(mp(i, j), k))==st.end())
            {
                dis[j][k]=dis[i][j]+1;
                qq.push(mp(j, k));
                prv[j][k]=i;
            }
    }
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int m, i, j, k, a, b, c, mn, mini;
    cin >> n >> m >>k;
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        g[a][b]=g[b][a]=1;
    }
    for(i=0; i<k; i++)
    {
        cin >> a >> b >> c;
        st.insert(mp(mp(a, b), c));
    }
    bfs();
    mn=inf;
    for(i=1; i<n; i++)
        if (dis[i][n]<mn)
        {
            mn=dis[i][n];
            mini=i;
        }
    if (mn==inf)
    {
        cout << "-1";
        return 0;
    }
    for(i=mini, j=n; i!=1; )
    {
        ans.pb(j);
        k=prv[i][j];
        j=i;
        i=k;
    }
    ans.pb(j);
    ans.pb(i);
    cout << mn << endl;
    for(i=ans.size()-1; i>=0; i--)
        cout << ans[i] << " ";
}