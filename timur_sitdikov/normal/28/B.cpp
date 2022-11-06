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

const int nmax = 105;
char g[nmax][nmax];
int col[nmax], d[nmax], n, per[nmax];

void dfs(int s, int cl)
{
    int i;
    col[s]=cl;
    for(i=1; i<=n; i++)
        if (g[s][i] && !col[i])
            dfs(i, cl);
}


int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, cl;
    cin >> n;
    for(i=1; i<=n; i++)
        cin >> per[i];
    for(i=1; i<=n; i++)
        cin >> d[i];
    for(i=1; i<=n; i++)
    {
        if (i-d[i]>0)
            g[i][i-d[i]]=g[i-d[i]][i]=1;
        if (i+d[i]<=n)
            g[i][i+d[i]]=g[i+d[i]][i]=1;
    }
    cl=0;
    for(i=1; i<=n; i++)
        if (!col[i]) 
            dfs(i, ++cl);
    for(i=1; i<=n; i++)
        if (col[per[i]]!=col[i]) 
        {
            printf("NO");
            return 0;
        }
    printf("YES");
}