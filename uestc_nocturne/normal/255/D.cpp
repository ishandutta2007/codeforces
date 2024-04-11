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
LL Cal(int x,int y,int t)
{
    if(t>=x+y-1)return (LL)x*y;
    LL ans=0;
    int sx=1,ex=t,sy=t,ey=1;
    if(t>y)
    {
        int all=t-y;
        ans+=(LL)all*y;
        sx=all+1;
        sy=y;
    }
    if(t>x)
    {
        ey=t-x+1;
        ex=x;
    }
    ans+=(LL)(ex-sx+1)*(ey+sy)/2;
    return ans;
}
LL C;
int n,x,y;
LL get(int t)
{
    t++;
    LL ans=0;
    ans+=Cal(x,y,t);
    ans+=Cal(n-x+1,y,t);
    ans+=Cal(x,n-y+1,t);
    ans+=Cal(n-x+1,n-y+1,t);
    ans++;
    ans-=min(x,t);
    ans-=min(n-x+1,t);
    ans-=min(y,t);
    ans-=min(n-y+1,t);
//  cout<<t<<" "<<ans<<endl;
    return ans;
}
int main()
{
    while(~scanf("%d%d%d%I64d",&n,&x,&y,&C))
    {
        int lo=-1,up=2*n+1;
        while(lo+1<up)
        {
            int mid=(lo+up)/2;
            if(get(mid)<C)lo=mid;
            else up=mid;
        }
        printf("%d\n",up);
    }
}