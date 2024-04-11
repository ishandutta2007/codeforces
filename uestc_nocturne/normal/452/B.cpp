/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
int n,m;
int sqr(int x){return x*x;}
double dis(int ax,int ay,int bx,int by)
{
    return sqrt(1.0*sqr(ax-bx)+1.0*sqr(ay-by));
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0)
        {
            printf("%d %d\n",0,m-1);
            printf("%d %d\n",0,0);
            printf("%d %d\n",0,m);
            printf("%d %d\n",0,1);
        }
        else if(m==0)
        {
            printf("%d %d\n",n-1,0);
            printf("%d %d\n",0,0);
            printf("%d %d\n",n,0);
            printf("%d %d\n",1,0);
        }
        else
        {
            double l1,l2;
            if(n<m)
            {
                l1=0;
                l1+=dis(0,0,n,m);
                l1+=dis(n,0,n,m);
                l1+=dis(n,0,0,m);
                l2=0;
                l2+=dis(n-1,m,0,0);
                l2+=dis(n,m,0,0);
                l2+=dis(n,m,1,0);
            }
            else
            {
                l1=0;
                l1+=dis(0,0,n,m);
                l1+=dis(0,m,n,m);
                l1+=dis(n,0,0,m);
                l2=0;
                l2+=dis(n,m-1,0,0);
                l2+=dis(n,m,0,0);
                l2+=dis(n,m,0,1);
            }
            if(l1>l2)
            {
                if(n<m)
                {
                    printf("%d %d\n",0,0);
                    printf("%d %d\n",n,m);
                    printf("%d %d\n",n,0);
                    printf("%d %d\n",0,m);
                }
                else
                {
                    printf("%d %d\n",0,0);
                    printf("%d %d\n",n,m);
                    printf("%d %d\n",0,m);
                    printf("%d %d\n",n,0);
                }
            }
            else
            {
                if(n<m)
                {
                    printf("%d %d\n",n-1,m);
                    printf("%d %d\n",0,0);
                    printf("%d %d\n",n,m);
                    printf("%d %d\n",1,0);
                }
                else
                {
                    printf("%d %d\n",n,m-1);
                    printf("%d %d\n",0,0);
                    printf("%d %d\n",n,m);
                    printf("%d %d\n",0,1);
                }
            }
        }
    }
}