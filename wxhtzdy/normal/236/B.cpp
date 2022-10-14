#include <bits/stdc++.h>
#define MAX 1000005
#define md 1073741824
using namespace std;

int cnt[MAX];

int divs(int x)
{
    int res=0;
    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0)res++;
        if(x%i==0&&i*i!=x)res++;
    }
    return res;
}

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int ans=0;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            for(int k=1;k<=c;k++)
            {
                if(cnt[i*j*k]==0)cnt[i*j*k]=divs(i*j*k);
                ans+=cnt[i*j*k];
                if(ans>=md)ans-=md;
            }
        }
    }
    printf("%d",ans);
}