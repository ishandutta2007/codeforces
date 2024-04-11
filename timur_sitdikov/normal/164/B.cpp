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

int m[2][2][1000005], v[2][2000005];

int main()
{   

    int n[2], i, j, mx=0, ind, lastind, tmp, tmp1;
    scanf("%d %d", &n[0], &n[1]);
    for(j=0; j<2; j++)
        for(i=0; i<=1000000; i++)
            m[j][0][i]=m[j][1][i]=-1;
    for(j=0; j<2; j++)
        for(i=0; i<n[j]; i++)
        {
            scanf("%d", &v[j][i]);
            v[j][i+n[j]]=v[j][i];
            m[j][0][v[j][i]]=i;
            m[j][1][v[j][i]]=i+n[j];
        }
    for(i=0, j=0; i<n[0]; i++)
    {
        if (m[1][0][v[0][i]]==-1) continue;
        if (j<=i) 
        {
            j=i+1;
        }
        if (m[1][0][v[0][j-1]]<m[1][0][v[0][i]]) lastind=m[1][1][v[0][j-1]];
        else lastind=m[1][0][v[0][j-1]];
        for(; j<2*n[0]; j++)
        {
            tmp=v[0][j-1];
            tmp1=v[0][j];
            if (tmp1==v[0][i]) break;
            ind=m[1][0][tmp1];
            if (ind==-1) break;
            if (ind<lastind) ind=m[1][1][tmp1];
            if (ind<lastind || ind>=m[1][0][v[0][i]]+n[1]) break;
            lastind=ind;
        }
        mx=max(mx, j-i);
    }
    printf("%d", mx);
}