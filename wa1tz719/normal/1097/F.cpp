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
bitset<7004> a[7005];
bitset<7004> c[7005];
bitset<7004> b[100005];
int miu[7005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i;
    for (i=1;i<=7000;i++)
    {
        int j;
        miu[i]=1;
        for (j=2;j*j<=i;j++)
        {
            if (i%(j*j)==0)
            {
                miu[i]=0;
            }
        }
    }
    for (i=1;i<=7000;i++)
    {
        int j;
        for (j=1;j<=7000;j++)
        {
            if (j%i==0)
            {
                a[i][j]=miu[j/i];
            }
            else
            {
                a[i][j]=0;
            }
        }
    }
    for (i=1;i<=7000;i++)
    {
        int j;
        for (j=1;j<=i;j++)
        {
            if (i%j==0)
            {
                c[i][j]=1;
            }
        }
    }
    int n,q;
    scanf("%d%d",&n,&q);
    int ttt;
    for (ttt=1;ttt<=q;ttt++)
    {
        int oper;
        scanf("%d",&oper);
        if (oper==1)
        {
            int x,v;
            scanf("%d%d",&x,&v);
            b[x]=c[v];
        }
        else if (oper==2)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            b[x]=b[y]^b[z];
        }
        else if (oper==3)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            b[x]=b[y]&b[z];
        }
        else
        {
            int x,v;
            scanf("%d%d",&x,&v);
            int p=(b[x]&a[v]).count();
            printf("%d",p%2);
        }
    }
    printf("\n");
    return 0;
}