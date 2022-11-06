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

char g[105][105];
int a[105], b[105], col[105], bad, m, n;
char c[200];

void dfs(int s, int cl)
{
    col[s]=cl;
    int i;
    for(i=0; i<m; i++)
        if (g[s][i])
        {
            if (col[i]==col[s]) 
                bad=1;
            if (!col[i]) dfs(i, 3-cl);
        }
}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, j, x, y;
    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
        if (a[i]>b[i]) swap(a[i], b[i]);
    }
    for(i=0; i<m; i++)
        for(j=i+1; j<m; j++)
            if (a[i]<a[j] && a[j]<b[i] && b[i]<b[j] || a[j]<a[i] && a[i]<b[j] && b[j]<b[i]) g[i][j]=g[j][i]=1;
    for(i=0; i<m; i++)
        if (!col[i]) dfs(i, 1);
    if (bad) {printf("Impossible"); return 0;}
    c[1]='i'; c[2]='o';
    for(i=0; i<m; i++) putchar(c[col[i]]);
}