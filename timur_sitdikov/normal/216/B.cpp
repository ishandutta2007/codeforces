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

char g[105][105], col[105];
int prv[105], n;
int num, tmp;

void dfs(int s)
{
    int i;
    col[s]=1;
    num++;
    for(i=1; i<=n; i++)
        if (g[s][i] && i!=prv[s])
        {
            if (!col[i])
            {
                prv[i]=s;
                dfs(i);
            }
            else tmp=1;
        }
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int m, a, b, i, ans=0;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        g[a][b]=g[b][a]=1;
    }
    for(i=1; i<=n; i++)
    {
        if (!col[i])
        {
            num=0;
            tmp=0;
            dfs(i);
            if (tmp && (num&1))
                ans++;
        }
    }
    if ((n-ans)&1)
        ans++;
    cout << ans;
}