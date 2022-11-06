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

char g[105][105], col[105];
int sum[105][105], n, s1, s2, last;
void dfs(int s)
{
    int i;
    col[s]=1;
    for(i=1; i<=n; i++)
    {
        if (g[s][i] && !col[i])
        {
            last=i;
            s1+=sum[s][i];
            dfs(i);
        }
    }
}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int a, b, c, i;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        g[a][b]=g[b][a]=1;
        sum[b][a]=c;
        s2+=c;
    }
    dfs(1);
    s1+=sum[last][1];
    printf("%d", min(s1, s2-s1));
}