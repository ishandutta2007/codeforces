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

vector <pair <int,int> > m[2];
int v[2][100005], iind[100005], tp;

bool cmp(pair <int,int>  a, pair <int,int>  b)
{return a.first>b.first;}

int main()
{   

    int i0, i1, i, j, pos0, pos1, n, a, b, v1, ans=0, sz[2], lim, mx, ss, cur;
    scanf("%d %d", &n, &v1);
    for(i=1; i<=n; i++)
    {
        scanf("%d %d", &a, &b);
        a--;
        m[a].push_back(make_pair(b, i));
    }
    sort (m[0].begin(), m[0].end(), cmp);
    sort (m[1].begin(), m[1].end(), cmp);
    sz[0]=m[0].size();
    sz[1]=m[1].size();
    for(i=1; i<=sz[0]; i++)
    {
        v[0][i]=v[0][i-1]+m[0][i-1].first;
    }
    for(i=1; i<=sz[1]; i++)
    {
        v[1][i]=v[1][i-1]+m[1][i-1].first;
    }
    mx=0; pos0=pos1=0;
    for(i0=0; i0<=sz[0]; i0++)
    {
        if (i0==v1+1) break;
        i1=min(sz[1], (v1-i0)/2);
        cur=v[0][i0]+v[1][i1];
        if (cur>mx)
        {
            mx=cur;
            pos0=i0;
            pos1=i1;
        }
    }
    printf("%d\n", mx);
    for(i=0; i<pos0; i++)
        iind[tp++]=m[0][i].second;
    for(i=0; i<pos1; i++)
        iind[tp++]=m[1][i].second;
    sort(iind, iind+tp);
    for(i=0; i<tp; i++)
        printf("%d ", iind[i]);
}