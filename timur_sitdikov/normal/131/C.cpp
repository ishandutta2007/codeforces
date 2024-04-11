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

int cmp(const void *c1, const void *c2)
{return *(int*)c1-*(int*)c2;}

bool cmp(int a, int b)
{return a<b;}

long long c[61][61];

int main()
{   

    long long i, j, n, m, t, ans=0;
    for(i=0; i<=60; i++) c[0][i]=1;
    for(j=1; j<=60; j++)
        for(i=1; i<=j; i++)
            c[i][j]=c[i-1][j-1]+c[i][j-1];
    scanf("%I64d %I64d %I64d", &n, &m, &t);
    for(i=1; i<=t-4; i++)
        ans+=c[i][m]*c[t-i][n];
    printf("%I64d", ans);
}