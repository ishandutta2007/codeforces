#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

char g[201][201];

int n, dis[201];
int col[201];
queue <int> qq;

void bfs(int s, int cl)
{
    int tmp, t;
    col[s]=cl; dis[s]=0;
    qq.push(s);
    while(!qq.empty())
    {
        tmp=qq.front();
        qq.pop();
        for(t=1; t<=n; t++)
        {
            if (g[tmp][t] && !col[t])
            {
                col[t]=cl;
                dis[t]=dis[tmp]+1;
                qq.push(t);
            }
        }
    }
}

int main()
{   
 
    int i, j, k, k1, a, b, v[2], ind, maxi, max=-1, tmp1, tmp2;
    scanf("%d", &n);
    for(i=1; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        g[a][b]=g[b][a]=1;
    }
    for(i=1; i<n; i++)
        for(j=i+1; j<=n; j++)
            if (g[i][j])
            {
                g[i][j]=g[j][i]=ind=0;
                for(k=1; k<=n; k++) col[k]=dis[k]=0;
                for(k=1; k<=n; k++) 
                    if (!col[k])
                    {
                        v[ind]=-1;
                        bfs(k, ind+1);
                        for(k1=1; k1<=n; k1++)
                            if (col[k1]==ind+1 && dis[k1]>v[ind]) 
                            {v[ind]=dis[k1]; maxi=k1;}
                        for(k1=1; k1<=n; k1++) 
                            if (col[k1]==ind+1) {col[k1]=dis[k1]=0;}
                        bfs(maxi, ind+1);
                        for(k1=1; k1<=n; k1++)
                            if (col[k1]==ind+1 && dis[k1]>v[ind]) 
                            {v[ind]=dis[k1]; maxi=k1;}
                        ind++;
                    }
                if (v[0]*v[1]>max) 
                    max=v[0]*v[1];
                g[i][j]=g[j][i]=1;
            }
    printf("%d\n", max);
}