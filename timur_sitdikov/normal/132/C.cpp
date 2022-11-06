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

char c[105];
int ans[105][105][2], bi=-1000000, lim;

void fill(int dir)
{
    int i, j, l, cur=0, ind;
    l=strlen(c);
    for(i=0; i<l; i++)
        for(j=0; j<=lim; j++)
            ans[i][j][0]=ans[i][j][1]=bi;
    for(i=0; i<l; i++)
    {
        if (c[i]=='F') cur+=dir;
        else dir=-dir;
        ind=(dir==1? 1: 0);
        ans[i][0][ind]=cur;
    }
}

int calc()
{
    int i, j, mx, l=strlen(c);
    if (c[0]=='F')
    {
        ans[0][0][1]=1;
        ans[0][1][1]=bi;
        ans[0][0][0]=bi;
        ans[0][1][0]=0;
    }
    else
    {
        ans[0][0][1]=bi;
        ans[0][1][1]=1;
        ans[0][0][0]=0;
        ans[0][1][0]=bi;
    }
    for(i=1; i<l; i++)
        for(j=1; j<=min(lim, i+1); j++)
        {
            if (c[i]=='F')
            {
                ans[i][j][1]=max(ans[i-1][j][1]+1, ans[i-1][j-1][0]);
                ans[i][j][0]=max(ans[i-1][j][0]-1, ans[i-1][j-1][1]);               
            }
            else
            {
                ans[i][j][1]=max(ans[i-1][j][0], ans[i-1][j-1][1]+1);
                ans[i][j][0]=max(ans[i-1][j][1], ans[i-1][j-1][0]-1);
            }
        }
    mx=-1;
    for(i=lim&1; i<=lim; i+=2)
    {
        mx=max(mx, ans[l-1][i][1]);
        mx=max(mx, ans[l-1][i][0]);
    }
    return mx;
}

int main()
{   
    int mx;
    scanf("%s %d", &c, &lim);
    fill(1); mx=calc();
    fill(-1); mx=max(mx, calc());
    printf("%d", mx);
}