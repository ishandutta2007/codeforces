#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int xors_b[5005];
int xors_p[5005];
int p[5005],b[5005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        printf("? %d %d\n",0,i);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        xors_b[i]=x;
    }
    for (i=1;i<n;i++)
    {
        printf("? %d %d\n",i,0);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        xors_p[i]=x^xors_b[0];
    }
    int cnt=0;
    for (i=0;i<n;i++)
    {
        p[0]=i;
        int j;
        for (j=1;j<n;j++)
        {
            p[j]=p[0]^xors_p[j];
        }
        for (j=0;j<n;j++)
        {
            b[j]=p[0]^xors_b[j];
        }
        for (j=0;j<n;j++)
        {
            if (p[b[j]]!=j) break;
        }
        if (j==n)
        {
            cnt++;
        }
    }
    for (i=0;i<n;i++)
    {
        p[0]=i;
        int j;
        for (j=1;j<n;j++)
        {
            p[j]=p[0]^xors_p[j];
        }
        for (j=0;j<n;j++)
        {
            b[j]=p[0]^xors_b[j];
        }
        for (j=0;j<n;j++)
        {
            if (p[b[j]]!=j) break;
        }
        if (j==n)
        {
            printf("!\n");
            printf("%d\n",cnt);
            int j;
            for (j=0;j<n;j++)
            {
                printf("%d ",p[j]);
            }
            printf("\n");
            return 0;
        }
    }
    return 0;
}