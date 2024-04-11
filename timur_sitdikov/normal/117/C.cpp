#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

char g[5005][5005], col[5000];
int n, prev[5000];

int dfs(int s)
{
    int i, tmp;
    col[s]=1;
    for(i=0; i<n; i++)
        if (g[s][i])
        { 
            if(!col[i])
            {
                prev[i]=s;
                tmp=dfs(i);
                if (tmp!=-1) return tmp;
            }
            else if (col[i]==1 && i!=prev[s]) 
                return s;
        }
    col[s]=2;
    return -1;
}

int main()
{   

    int i, j, k, v;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s", &g[i]);
        for(j=0; j<n; j++) g[i][j]-='0';
        prev[i]=-1;
    }
    for(i=0; i<n; i++)
        if (!col[i])
        {
            v=dfs(i);
            if (v!=-1)
            {
                for(j=0; j<n; j++)
                    for(k=0; k<n; k++)
                        if (g[v][j] && g[k][v] && g[j][k]) 
                        {printf("%d %d %d", v+1, j+1, k+1); return 0;}
            }
        }
    printf("-1");
}