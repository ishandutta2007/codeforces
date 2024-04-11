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

const int maxn=1010;
char c[maxn][maxn];
int col[200];

char find_col(int i, int j, int f)
{
    int k;
    for(k=1; k<=4; k++)
        col[k]=0;
    if (!f)
    {
        for(k=0; k<3; k++)
        {
            col[c[i-1][j+k]]=1;
            col[c[i+1][j+k]]=1;
        }
        col[c[i][j-1]]=col[c[i][j+3]]=1;
    }
    else
    {
        for(k=0; k<3; k++)
        {
            col[c[i+k][j-1]]=1;
            col[c[i+k][j+1]]=1;
        }
        col[c[i-1][j]]=col[c[i+3][j]]=1;
    }
    for(k=1; k<=4; k++)
        if (!col[k])
            return k;
    return 0;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, i, j, f, tmp;
    cin >> n >> m;
    for(i=1; i<=n; i++)
        scanf("%s", &c[i][1]);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if (c[i][j]=='b')
            {
                printf("NO");
                return 0;
            }
            if (c[i][j]=='w')
            {
                if (c[i][j+1]=='b' && c[i][j+2]=='w')
                {
                    tmp=find_col(i, j, 0);
                    if (!tmp)
                    {
                        printf("NO");
                        return 0;
                    }
                    c[i][j]=c[i][j+1]=c[i][j+2]=tmp;
                }
                else if (c[i+1][j]=='b' && c[i+2][j]=='w')
                {
                    tmp=find_col(i, j, 1);
                    if (!tmp)
                    {
                        printf("NO");
                        return 0;
                    }
                    c[i][j]=c[i+1][j]=c[i+2][j]=tmp;
                }
                else
                {
                    printf("NO");
                    return 0;
                }
            }
        }
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if (c[i][j]!='.')
                c[i][j]=c[i][j]-1+'a';
    printf("YES\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
            putchar(c[i][j]);
        putchar('\n');
    }
}