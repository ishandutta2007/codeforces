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


const int maxn=105;
char g[maxn][maxn], col[maxn];
int x[maxn], y[maxn], n;

void dfs(int s)
{
    col[s]=1;
    for(int i=1; i<=n; i++)
        if (!col[i] && g[s][i])
            dfs(i);
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j, ans;
    cin >> n;
    for(i=1; i<=n; i++)
        cin >> x[i] >> y[i];
    for(i=1; i<=n; i++)
        for(j=i+1; j<=n; j++)
            if (x[i]==x[j] || y[i]==y[j])
                g[i][j]=g[j][i]=1;
    ans=-1;
    for(i=1; i<=n; i++)
        if (!col[i])
        {
            dfs(i);
            ans++;
        }
    cout << ans;
}