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
int n,K,a[V];
int main()
{
    while(~scanf("%d%d",&n,&K))
    {
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        sort(a,a+n);
        int ret=0;
        for(int i=n-1;i>=0;i-=K)
        {
            ret+=2*a[i]-2;
        }
        printf("%d\n",ret);
    }
    return 0;
}