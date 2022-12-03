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
int n,k;
int flag1,flag2;
int e[1005];
void output1()
{
    int i;
    if (flag1==0)
    {
        for (i=0;i<n;i++)
        {
            printf("%d ",e[i]+1);
        }
        printf("\n");
    }
    else
    {
        for (i=n-1;i>=0;i--)
        {
            printf("%d ",e[i]+1);
        }
        printf("\n");
    }
}
void output2()
{
    int i;
    if (flag2==0)
    {
        for (i=0;i<n;i++)
        {
            printf("%d ",e[i]+1);
        }
        printf("\n");
    }
    else
    {
        for (i=n-1;i>=0;i--)
        {
            printf("%d ",e[i]+1);
        }
        printf("\n");
    }
}
void find_ans(int a,int b,int c)
{
    //a-->b; a-->c;
    if ((k<n)||(n==3))
    {
        puts("-1");
        return;
    }
    int w;
    int i;
    for (i=0;i<n;i++)
    {
        if ((i!=a)&&(i!=b)&&(i!=c))
        {
            w=i;
            break;
        }
    }
    e[0]=a;
    e[1]=w;
    e[2]=c;
    int sum=3;
    for (i=0;i<n;i++)
    {
        if ((i!=a)&&(i!=b)&&(i!=c)&&(i!=w))
        {
            e[sum++]=i;
        }
    }
    e[sum]=b;
    output1();
    e[0]=a;
    e[1]=w;
    e[2]=b;
    sum=3;
    for (i=n-1;i>=0;i--)
    {
        if ((i!=a)&&(i!=b)&&(i!=c)&&(i!=w))
        {
            e[sum++]=i;
        }
    }
    e[sum]=c;
    output2();
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d%d",&n,&k);
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if ((a==b)||(c==d))
    {
        puts("-1");
        return 0;
    }
    a--;
    b--;
    c--;
    d--;
    if (a>b)
    {
        flag1=1;
        swap(a,b);
    }
    if (c>d)
    {
        flag2=1;
        swap(c,d);
    }
    if (k<n-1)
    {
        puts("-1");
        return 0;
    }
    if ((a==c)&&(b==d))
    {
        int i;
        for (i=0;i<n;i++)
        {
            e[i]=i;
        }
        swap(e[0],e[a]);
        swap(e[n-1],e[b]);
        output1();
        output2();
    }
    else
    {
        if ((a==c)||(a==d))
        {
            if (a==d) find_ans(a,b,c);
            flag2^=1;
            if (a==c) find_ans(a,b,d);
        }
        else if ((b==c)||(b==d))
        {
            flag1^=1;
            if (a==d) find_ans(b,a,c);
            flag2^=1;
            if (a==c) find_ans(b,a,d);
        }
        else
        {
            if ((k<n+1)||(n<=4))
            {
                puts("-1");
                return 0;
            }
            int w;
            int i;
            for (i=0;i<n;i++)
            {
                if ((i!=a)&&(i!=b)&&(i!=c)&&(i!=d))
                {
                    w=i;
                    break;
                }
            }
            e[0]=a;
            e[1]=c;
            e[2]=w;
            e[3]=d;
            int sum=4;
            for (i=0;i<n;i++)
            {
                if ((i!=a)&&(i!=b)&&(i!=c)&&(i!=d)&&(i!=w))
                {
                    e[sum++]=i;
                }
            }
            e[n-1]=b;
            output1();
            e[0]=c;
            e[1]=a;
            e[2]=w;
            e[3]=b;
            sum=4;
            for (i=n-1;i>=0;i--)
            {
                if ((i!=a)&&(i!=b)&&(i!=c)&&(i!=d)&&(i!=w))
                {
                    e[sum++]=i;
                }
            }
            e[n-1]=d;
            output2();
        }
    }
    return 0;
}