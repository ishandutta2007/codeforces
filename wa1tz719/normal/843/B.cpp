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
int a[50005];
int main()
{
    #ifdef absi2011
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    srand(time(0));
    int n,start,x;
    scanf("%d%d%d",&n,&start,&x);
    int i;
    for (i=0;i<n;i++)
    {
        a[i]=i;
    }
    for (i=0;i<100;i++)
    {
        random_shuffle(a,a+n);
    }
    int big=-1,small=-1;
    int big_id,small_id;
    for (i=0;i<1000;i++)
    {
        if (i>=n) break;
        printf("? %d\n",a[i]+1);
        fflush(stdout);
        int xx,yy;
        scanf("%d%d",&xx,&yy);
        if (xx>=x)
        {
            if (big==-1)
            {
                big=xx;
                big_id=a[i];
            }
            if (big>xx)
            {
                big=xx;
                big_id=a[i];
            }
        }
        else
        {
            if (small==-1)
            {
                small=xx;
                small_id=a[i];
            }
            else if (xx>small)
            {
                small=xx;
                small_id=a[i];
            }
        }
    }
    if (small==-1)
    {
        small_id=start-1;
    }
    if (big==-1)
    {
        big_id=-1;
    }
    int now=small_id;
    for (;;)
    {
        printf("? %d\n",now+1);
        fflush(stdout);
        int xx,yy;
        scanf("%d%d",&xx,&yy);
        if (xx>=x)
        {
            printf("! %d\n",xx);
            break;
        }
        now=yy-1;
        if (now==-2)
        {
            printf("! -1\n");
            break;
        }
    }
    #ifdef absi2011
    system("pause");
    #endif
    return 0;
}