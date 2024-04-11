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

int ans[165][165][165], mx[165][165], ans2[165][165];
int val[165];
char c[165];

int is_pal(int i, int j)
{
    int k;
    for(k=0; k<=j-i; k++)
        if (c[k+i]!=c[j-k]) return 0;
    return 1;
}

int main()
{   
    int i, j, i1, j1, k, k1, n, k2, ret=0;
    for(i=0; i<160; i++) val[i]=-1;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &val[i+1]);
    scanf("%s", &c);
    for(i=0; i<n; i++)
        for(j=i; j<n; j++)
        {
            mx[i][j]=-1;
            for(k=0; k<=n; k++)
                ans[i][j][k]=-1;
        }
    for(i=0; i<n; i++)
    {
        ans[i][i][1]=0;
        if (val[1]!=-1) mx[i][i]=val[1];
    }
    for(i1=1; i1<n; i1++)
        for(i=0; i<n-i1; i++)
        {
            j=i+i1;
            if (c[i]==c[j])
            {
                if(i1>=2)
                {
                    for(k=1; k<=n; k++)
                        ans[i][j][k+2]=max(ans[i][j][k+2], ans[i+1][j-1][k]);           
                    for(k=1; k<=n; k++)
                        if (ans[i+1][j-1][k]!=-1 && val[k]!=-1)
                            ans[i][j][2]=max(ans[i][j][2], ans[i+1][j-1][k]+val[k]);
                }
                else ans[i][j][2]=0;
            }
            for(k=1; k<=n; k++)
            {
                for(k1=i; k1<j; k1++)
                {
                    if (ans[i][k1][k]!=-1 && mx[k1+1][j]!=-1)
                        ans[i][j][k]=max(ans[i][j][k], ans[i][k1][k]+mx[k1+1][j]);
                    if (mx[i][k1]!=-1 && ans[k1+1][j][k]!=-1)
                        ans[i][j][k]=max(ans[i][j][k], mx[i][k1]+ans[k1+1][j][k]);
                }
            }
            for(k=1; k<=j-i+1; k++)
                if (ans[i][j][k]+val[k]>mx[i][j] && ans[i][j][k]!=-1 && val[k]!=-1)
                    mx[i][j]=ans[i][j][k]+val[k];
        }
    for(i=0; i<n; i++)
        for(j=i; j<n; j++)
            for(k=1; k<=n; k++)
            {
                if (ans[i][j][k]+val[k]>mx[i][j] && ans[i][j][k]!=-1 && val[k]!=-1)
                        mx[i][j]=ans[i][j][k]+val[k];
                if (ans[i][j][k]>mx[i][j])
                    mx[i][j]=ans[i][j][k];
            }
    for(i1=0; i1<n; i1++)
        for(i=0; i<n-i1; i++)
        {
            j=i+i1;
            ans2[i][j]=mx[i][j];
            for(k=0; k<i1; k++)
                ans2[i][j]=max(ans2[i][j], ans2[i][i+k]+ans2[i+k+1][j]);
        }
    for(i=0; i<n; i++)
        for(j=i; j<n; j++)
            if (ret<ans2[i][j]) ret=ans2[i][j];
    printf("%d", ret);
}