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
#define mp make_pair

const int nmax = 200105;
const int inf = 10000000;
char c[2][nmax];
int dis[2][nmax], col[2][nmax], n;
queue <pair<int, int>> qq;

int check(int i, int j, int i1, int j1)
{
    if (j1<0 || c[i1][j1]=='X' || col[i1][j1] || dis[i][j]>=j1) return 0;
    if (j1>=n) 
        return 1;
    col[i1][j1]=1;
    dis[i1][j1]=dis[i][j]+1;
    qq.push(mp(i1, j1));
    return 0;
}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, j, k, f;
    scanf("%d %d %s %s", &n, &k, &c[0], &c[1]);
    for(i=0; i<2; i++)
        for(j=0; j<=n+k; j++)
            dis[i][j]=inf;
    dis[0][0]=0;
    qq.push(mp(0, 0));
    f=0;
    while(!qq.empty())
    {
        i=qq.front().first;
        j=qq.front().second;
        qq.pop();
        if (check(i, j, 1-i, j+k) || check(i, j, i, j+1))
        {
            printf("YES");
            return 0;
        }
        check(i, j, i, j-1);
    }
    printf("NO");
}