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
const int V=100100;
int a[V],n;
int main()
{
    while(~scanf("%d",&n))
    {
        int mx=0;
        LL s=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            mx=max(mx,a[i]);
            s+=a[i];
        }
        int ret=s/(n-1);
        if(s%(n-1))ret++;
        ret=max(mx,ret);
        printf("%d\n",ret);
    }
}