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
int a[V],i,n,lo,up,mid,te,ct;
int ans[V*4];
int main()
{
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        sort(a,a+n);
        lo=0;up=n;
        while(lo+1<up)
        {
            mid=(lo+up)/2;
            te=1;ct=1;
            for(i=1;i<n;i++)
            {
                if(a[i]==a[i-1])
                {
                    if(te<mid)
                    {
                        te++;ct++;
                    }
                }
                else
                {
                    ct++;te=1;
                }
            }
            if(ct>=3*mid)lo=mid;
            else up=mid;
        }
        printf("%d\n",lo);
        if(lo==0)continue;
        te=1;ct=1;
        ans[0]=a[0];
        for(i=1;i<n;i++)
        {
            if(ct==3*lo)break;
            if(a[i]==a[i-1])
            {
                if(te<lo)
                {
                    te++;
                    ans[ct]=a[i];
                    ct++;
                }
            }
            else
            {
                te=1;
                ans[ct]=a[i];
                ct++;
            }
        }
        for(i=0;i<lo;i++)
        {
            printf("%d %d %d\n",ans[i+2*lo],ans[i+lo],ans[i]);
        }
    }
}