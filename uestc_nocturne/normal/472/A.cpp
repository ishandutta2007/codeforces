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
const int N=1000000;
int is[V],n;
int main()
{
    memset(is,0,sizeof(is));
    for(int i=2;i<=N;i++)
    {
        if(is[i])continue;
        for(int j=2*i;j<=N;j+=i)
        is[j]=1;
    }
    while(~scanf("%d",&n))
    {
        for(int i=2;i<n;i++)
        {
            if(is[i]&&is[n-i])
            {
                printf("%d %d\n",i,n-i);
                break;
            }
        }
    }
    return 0;
}