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

char g[1005][1005];
vector <pair<int, int>> gr;
queue <pair <int, int> > qq;

int bfs0(int i0, int j0)
{
    int f=0, i, j, i1, j1;
    while (!qq.empty()) qq.pop();
    qq.push(make_pair(i0, j0));
    g[i0][j0]='2';
    while(!qq.empty())
    {
        i=qq.front().first;
        j=qq.front().second;
        qq.pop();
        for(i1=-1; i1<=1; i1++)
            for(j1=-1; j1<=1; j1++)
            {
                if (g[i+i1][j+j1]=='0')
                {
                    g[i+i1][j+j1]='2';
                    qq.push(make_pair(i+i1, j+j1));
                }
                else if (g[i+i1][j+j1]=='#')
                    f=1;
                else if (g[i+i1][j+j1]=='1')
                {
                    gr.push_back(make_pair(i+i1, j+j1));
                    g[i+i1][j+j1]='3';
                }
            }
    }
    return f;
}

int bfs3()
{
    int k, i, j, i0, j0, i1, j1, s, sz=gr.size();
    i0=gr[0].first;  j0=gr[0].second;
    while (!qq.empty()) qq.pop();
    qq.push(make_pair(i0, j0));
    g[i0][j0]='2';
    while(!qq.empty())
    {
        i=qq.front().first;
        j=qq.front().second;
        qq.pop();
        for(i1=-1; i1<=1; i1++)
            for(j1=-1; j1<=1; j1++)
                if (abs(i1)+abs(j1)==1 && g[i+i1][j+j1]=='3')
                {
                    g[i+i1][j+j1]='1';
                    qq.push(make_pair(i+i1, j+j1));
                }
    }
    for(k=0; k<sz; k++)
        for(k=0; k<sz; k++)
        {
            i=gr[k].first; j=gr[k].second;
            if (g[i][j]=='3') return 1;
        }
    return 0;
}

int check()
{
    int k, i, j, i1, j1, s, sz=gr.size();
    for(k=0; k<sz; k++)
    {
        i=gr[k].first; j=gr[k].second;
        s=0;
        for(i1=-1; i1<=1; i1++)
            for(j1=-1; j1<=1; j1++)
            {               
                if (abs(i1)+abs(j1)==1)
                {
                    if (g[i+i1][j+j1]=='3') s++;
                }
            }
        if (s!=2) 
            return 1;
    }
    return 0;
}

void norm()
{
    int k, i, j, sz=gr.size();
    for(k=0; k<sz; k++)
    {
        i=gr[k].first; j=gr[k].second;
        g[i][j]='1';
    }
}

int main()
{   
    int n, m, i, j, mx=0;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++)
        scanf("%s", &g[i][1]);
    for(i=0; i<=n+1; i++)
        g[i][0]=g[i][m+1]='#';
    for(j=0; j<=m+1; j++)
        g[0][j]=g[n+1][j]='#';
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if (g[i][j]=='0')
            {
                gr.clear();
                if (bfs0(i, j)) {norm(); continue;}
                if (gr.size()<=mx) {norm(); continue;}
                if (check()) {norm(); continue;}
                if (bfs3()) {norm(); continue;}
                mx=gr.size();
                norm();
            }
    for(i=2; i<=n; i++)
        for(j=2; j<=m; j++)
            if(g[i][j]=='1' && g[i-1][j]=='1' && g[i][j-1]=='1' && g[i-1][j-1]=='1') mx=max(mx, 4);
    printf("%d", mx);
}