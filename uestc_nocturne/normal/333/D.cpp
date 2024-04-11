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
const int V=1010;
int a[V][V],b[V*V],c[V][V],d[V];
int n,m;
bool check(int x)
{
    memset(c,0,sizeof(c));
    for(int i=0;i<n;i++)
    {
        int t=0;
        for(int j=0;j<m;j++)
        if(a[i][j]>=x)
        d[t++]=j;
        for(int j=0;j<t;j++)
        for(int k=0;k<j;k++)
        {
            if(c[d[j]][d[k]])return true;
            c[d[j]][d[k]]=1;
        }
    }
    return false;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            b[i*m+j]=a[i][j];
        }
        int N=n*m;
        sort(b,b+N);
        int lo=-1,up=N;
        while(lo+1<up)
        {
            int mid=(lo+up)/2;
            if(check(b[mid]))lo=mid;
            else up=mid;
        }
        printf("%d\n",b[lo]);
    }
}