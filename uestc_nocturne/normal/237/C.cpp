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
const int V=1001000;
bool is[V];
int s[V];
void init()
{
    memset(is,0,sizeof(is));
    is[1]=1;s[0]=0;
    for(int i=2;i<=1000000;i++)
    {
        if(is[i])continue;
        for(int j=2*i;j<=1000000;j+=i)
        is[j]=1;
    }
    for(int i=1;i<=1000000;i++)
    if(is[i])s[i]=s[i-1];
    else s[i]=s[i-1]+1;
}
int a,b,K;
bool check(int mid)
{
    for(int i=a;i+mid-1<=b;i++)
    if(s[i+mid-1]-s[i-1]<K)return false;
    return true;
}
int main()
{
    init();
    while(~scanf("%d%d%d",&a,&b,&K))
    {
        int lo=0,up=b-a+2,mid;
        while(lo+1<up)
        {
            mid=(lo+up)/2;
            if(check(mid))up=mid;
            else lo=mid;
        }
        if(up!=b-a+2&&check(up))printf("%d\n",up);
        else puts("-1");
    }
}