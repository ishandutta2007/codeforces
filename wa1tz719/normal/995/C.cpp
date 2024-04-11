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
struct vv
{
    int x;
    int y;
    int id;
};
vv v[100005];
int ans[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    srand(time(0));
    int n;
    scanf("%d",&n);
    int nowx=0,nowy=0;
    int i;
    for (i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[i].id=i;
        v[i].x=x;
        v[i].y=y;
        long long t1=(long long)(nowx-x)*(nowx-x)+(long long)(nowy-y)*(nowy-y);
        long long t2=(long long)(nowx+x)*(nowx+x)+(long long)(nowy+y)*(nowy+y);
        if (t1<t2)
        {
            ans[i]=-1;
            nowx-=x;
            nowy-=y;
        }
        else
        {
            ans[i]=1;
            nowx+=x;
            nowy+=y;
        }
    }
    if ((long long)nowx*nowx+(long long)nowy*nowy>(long long)1500000*1500000)
    {
        for (;;)
        {
            random_shuffle(v,v+n);
            int nowx=0,nowy=0;
            for (i=0;i<n;i++)
            {
                int x=v[i].x;
                int y=v[i].y;
                long long t1=(long long)(nowx-x)*(nowx-x)+(long long)(nowy-y)*(nowy-y);
                long long t2=(long long)(nowx+x)*(nowx+x)+(long long)(nowy+y)*(nowy+y);
                if (t1<t2)
                {
                    ans[v[i].id]=-1;
                    nowx-=x;
                    nowy-=y;
                }
                else
                {
                    ans[v[i].id]=1;
                    nowx+=x;
                    nowy+=y;
                }
            }
            if ((long long)nowx*nowx+(long long)nowy*nowy<=(long long)1500000*1500000)
            {
                for (i=0;i<n;i++)
                {
                    printf("%d ",ans[i]);
                }
                printf("\n");
                return 0;
            }
        }
    }
    for (i=0;i<n;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}