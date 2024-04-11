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

queue <pair<int, int> > qq;
pair<int, int> lst;
char col[2005][2005];
int n, m;

void bfs()
{
    int i, j, i11, j11, i22, j22;
    while(!qq.empty())
    {
        i11=qq.front().first;
        j11=qq.front().second;
        qq.pop();
        for(i=-1; i<=1; i++)
            for(j=-1; j<=1; j++)
                if (abs(i+j)==1)
                {
                    i22=i+i11;
                    j22=j+j11;
                    if (!col[i22][j22])
                    {
                        col[i22][j22]=1;
                        lst=mp(i22, j22);
                        qq.push(lst);                   
                    }
                }
    }
}

int main()
{   
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int k, i, a, b;
    cin >> n >> m >> k;
    for(i=0; i<=n+1; i++)
        col[i][0]=col[i][m+1]=1;
    for(i=0; i<=m+1; i++)
        col[0][i]=col[n+1][i]=1;
    for(i=0; i<k; i++)
    {
        cin >> a >> b;
        lst=mp(a, b);
        qq.push(mp(a, b));
        col[a][b]=1;
    }
    bfs();
    cout << lst.first << " " << lst.second;
    
}