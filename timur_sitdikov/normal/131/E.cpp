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

struct fer{int par[4], ind;} fr[100005];
int ans[10];
int bt[100005];

int ind;

bool cmp(fer a, fer b)
{
    if (a.par[ind]==b.par[ind]) 
    {
        if (ind==0)
        return a.par[1]<b.par[1];
        else return a.par[0]<b.par[0];
    }
    else return a.par[ind]<b.par[ind];
}

int main()
{   
    int n, i, j, m;
    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &fr[i].par[0], &fr[i].par[1]);
        fr[i].par[2]=fr[i].par[0]+fr[i].par[1];
        fr[i].par[3]=fr[i].par[0]-fr[i].par[1];
        fr[i].ind=i;
    }
    for(j=0; j<4; j++)
    {
        ind=j;
        sort(fr, fr+m, cmp);
        for(i=1; i<m; i++)
            if (fr[i-1].par[j]==fr[i].par[j])
            {
                bt[fr[i-1].ind]++;
                bt[fr[i].ind]++;
            }
    }
    for(i=0; i<m; i++)
        ans[bt[i]]++;
    for(i=0; i<9; i++)
        printf("%d ", ans[i]);
}