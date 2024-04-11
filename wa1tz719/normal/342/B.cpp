#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct dwell
{
    int t;
    int l;
    int r;
};
dwell a[100010];
int main()
{
    int n,m,s,f;
    scanf("%d%d%d%d",&n,&m,&s,&f);
    int i; 
    for (i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i].t,&a[i].l,&a[i].r);
    }
    int times=0,where=s;
    int j;
    if (s<f)
    {
        for (i=1;i<=m;i++)
        {
            int delta=a[i].t-times;
            for (j=1;j<delta;j++)
            {
                printf("R");
                where++;
                if(where==f) break;
            }
            if (where==f) break;
            if ((a[i].l<=where+1)&&(where<=a[i].r))
            {
                printf("X");
            }
            else
            {
                printf("R");
                where++;
                if (where==f) break;
            }
            times=a[i].t;
        }
        for (i=where;i<f;i++)
        {
            printf("R");
        }
    }
    else
    {
        for (i=1;i<=m;i++)
        {
            int delta=a[i].t-times;
            for (j=1;j<delta;j++)
            {
                printf("L");
                where--;
                if (where==f)break;
            }
            if (where==f)break;
            if ((a[i].l<=where)&&(where-1<=a[i].r))
            {
                printf("X");
            }
            else
            {
                printf("L");
                where--;
                if(where==f)break;
            }
            times=a[i].t;
        }
        for (i=where;i>f;i--)
        {
            printf("L");
        }
    }
    printf("\n");
    return 0;
}