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
const int V=2100;
int x[V],n,K;
int main()
{
    while(~scanf("%d%d",&n,&K))
    {
        int ct=0;
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        ct++;
        if(K>=ct)
        {
            puts("no solution");
            continue;
        }
        x[0]=0;
        for(int i=1;i<n;i++)
        x[i]=x[i-1]+n-i;
        for(int i=0;i<n;i++)
        printf("0 %d\n",x[i]);
    }
}