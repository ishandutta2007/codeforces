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

const int maxn=105;

char g[maxn][maxn], col[maxn];
int n;
vector<int> ans;

int dfs(int s, int cl)
{
    int i, cl1;
    col[s]=cl;
    for(i=1; i<=n; i++)
        if (g[s][i])
        {
            if (g[s][i]==1)
                cl1=3-cl;
            else cl1=cl;
            if (!col[i])
            {
                if (dfs(i, cl1))
                    return 1;
            }
            else
            {
                if (cl1!=col[i])
                    return 1;
            }
        }
    return 0;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int m, a, b, c, i, j, f;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        cin >> a >> b >> c;
        g[a][b]=g[b][a]=1+c;
    }
    for(i=1;i<=n; i++)
        if (!col[i] && dfs(i, 1))
        {
            printf("Impossible");
            return 0;
        }
    for(i=1; i<=n; i++)
        if (col[i]==1)
            ans.pb(i);
    cout << ans.size() << endl;
    for(i=0; i<(int)ans.size(); i++)
        cout << ans[i] << " ";
}