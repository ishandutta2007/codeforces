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

const int maxn=1005;
int m[maxn][maxn];

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, i, j;
    cin >> n;
    for(i=1; i<=n; i++)
        for(j=i+1; j+i<=n; j++)
            m[i][j]=m[j][i]=(i+j-1)%n;
    for(i=1; i<=n; i++)
        for(j=max(n-i+1, i+1); j<n; j++)
            m[i][j]=m[j][i]=(i+j)%n;
    for(i=1; i<=n/2; i++)
        m[n][i]=m[i][n]=(2*i-1)%n;
    for(; i<=n; i++)
        m[n][i]=m[i][n]=(2*i)%n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            printf("%d ", m[i][j]);
        putchar('\n');
    }
}