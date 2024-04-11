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
int a[V],n,m,mi,x;
int main()
{
    while(~scanf("%d",&m))
    {
        mi=1001000;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            mi=min(mi,x);
        }
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        sort(a,a+n);
        int ret=0;
        for(int i=n-1;i>=0;i--)
        {
            if((n-1-i)%(mi+2)<mi)ret+=a[i];
        }
        printf("%d\n",ret);
    }
}