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
int n,x,y,px,py,ret,te;
int main()
{
    while(~scanf("%d",&n))
    {
        ret=1,te=0,px=-1;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            if(x==px&&y==py)te++;
            else te=1;
            ret=max(ret,te);
            px=x;py=y;
        }
        printf("%d\n",ret);
    }
}