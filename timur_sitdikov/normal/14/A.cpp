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

char c[60][60];

int main()
{   
   
    int n, m, i, j, l, r, t, b;
    scanf("%d %d", &m, &n);
    for(i=0; i<m; i++) scanf("%s", &c[i]);
    for(i=0; i<m; i++)
        for(j=0; j<n; j++) 
            if (c[i][j]=='*') {t=i; goto l1;}
l1: for(i=m-1; i>=0; i--)
        for(j=0; j<n; j++) 
            if (c[i][j]=='*') {b=i; goto l2;}
l2: for(j=0; j<n; j++)
        for(i=0; i<m; i++) 
            if (c[i][j]=='*') {l=j; goto l3;}
l3: for(j=n-1; j>=0; j--)
        for(i=0; i<m; i++) 
            if (c[i][j]=='*') {r=j; goto l4;}
l4: for(i=t; i<=b; i++)
    {
        for(j=l; j<=r; j++)
            putchar(c[i][j]);
        putchar('\n');
    }
}