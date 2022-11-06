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

char mp[1505][1505], col[1505][1505];
int offset[1505][1505][2];
queue <pair<int, int>> qq;
int n, m;

int bfs(int i, int j)
{
    int i1, j1, i2, j2, di, dj;
    col[i][j]=1;
    qq.push(make_pair(i, j));
    while(!qq.empty())  
    {
        i=qq.front().first;
        j=qq.front().second;
        qq.pop();
        for(i1=-1; i1<=1; i1++)
            for(j1=-1; j1<=1; j1++)
                if (abs(i1)+abs(j1)==1)
                {
                    di=dj=0;
                    i2=i+i1;
                    j2=j+j1;
                    if (i2<0) {di=-1; i2=n-1;}
                    if (i2>=n) {di=1; i2=0;}
                    if (j2<0) {dj=-1; j2=m-1;}
                    if (j2>=m) {dj=1; j2=0;}                    
                    if (mp[i2][j2]=='.')
                    {
                        if (col[i2][j2])
                        {
                            if (offset[i2][j2][1]!=offset[i][j][1]+dj ||
                                offset[i2][j2][0]!=offset[i][j][0]+di) return 1;
                        }
                        else 
                        {
                            offset[i2][j2][1]=offset[i][j][1]+dj;
                            offset[i2][j2][0]=offset[i][j][0]+di;
                            qq.push(make_pair(i2, j2));
                            col[i2][j2]=1;
                        }
                    }
                }
    }
    return 0;
}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++) scanf("%s", &mp[i]);
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if (mp[i][j]=='S') 
            {mp[i][j]='.'; goto l;}
l:  if (bfs(i, j)) printf("YES");
    else printf("NO");

}