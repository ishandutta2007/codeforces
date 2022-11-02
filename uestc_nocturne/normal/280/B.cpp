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
int l[V],r[V],a[V],ret,n;
int main()
{
    while(~scanf("%d",&n))
    {
        ret=0;
        for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)l[i]=r[i]=i;
        for(int i=1;i<=n;i++)
        {
            while(l[i]!=1&&a[l[i]-1]<a[i])l[i]=l[l[i]-1];
            if(l[i]!=1)ret=max(ret,a[i]^a[l[i]-1]);
        }
        for(int i=n;i>=1;i--)
        {
            while(r[i]!=n&&a[r[i]+1]<a[i])r[i]=r[r[i]+1];
            if(r[i]!=n)ret=max(ret,a[i]^a[r[i]+1]);
        }
        printf("%d\n",ret);
    }
}