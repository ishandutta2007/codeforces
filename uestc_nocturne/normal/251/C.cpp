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
LL dp[200][(1<<14)+10],a,b;
int gcd(int x,int y)
{
    if(!x)return y;
    if(!y)return x;
    return gcd(y,x%y);
}
int lcm(int x,int y)
{
    return x/gcd(x,y)*y;
}
const LL ooo=1000000001;
const LL oo=ooo*ooo;
int K;
int vis[1001000];
int main()
{
    while(cin>>a>>b)
    {
        scanf("%d",&K);
        LL now=a;
        memset(vis,-1,sizeof(vis));
        int cm=1;
        for(int i=2;i<=K;i++)
        cm=lcm(cm,i);
    //  cout<<cm<<endl;
        LL ans=0,use=-1;
        for(int i=0;;i++)
        {
            if(now==b)break;
            if(vis[now%cm]!=-1)
            {use=i-vis[now%cm];break;}
            vis[now%cm]=i;
            int dc=1;
            for(int j=2;j<=K;j++)
            if(now-(int)(now%j)>=b)dc=max(dc,(int)(now%j));
            now-=dc;
            ans++;
        }
    //  cout<<use<<endl;
        if(use!=-1)
        {
            LL d=now-b;
            LL tm=d/cm;
            ans+=tm*use;
            now-=tm*cm;
            for(int i=0;;i++)
            {
                if(now==b)break;
                int dc=1;
                for(int j=2;j<=K;j++)
                if(now-(int)(now%j)>=b)dc=max(dc,(int)(now%j));
                now-=dc;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}