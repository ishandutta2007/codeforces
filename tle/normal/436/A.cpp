#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int n,x,t[10001],h[100001],m[100001],ch,rp=0,ans=0;
bool did[10001];
int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>t[i]>>h[i]>>m[i];
    ch=x; rp=0;
    bool p=1;
    for(int i=1;i<=n;i++) did[i]=0;
    while(1)
    {
        p=!p;
        int maxh=-1,maxs=0;
        for(int i=1;i<=n;i++)
        {
            if(did[i]||h[i]>ch||t[i]!=p) continue;
            if(m[i]>maxh) maxh=m[i],maxs=i;
        }
        if(maxs==0) break;
        did[maxs]=1; ch+=m[maxs]; rp++;
    }
    ans=max(ans,rp);
    ch=x; rp=0;
    p=0;
    for(int i=1;i<=n;i++) did[i]=0;
    while(1)
    {
        p=!p;
        int maxh=-1,maxs=0;
        for(int i=1;i<=n;i++)
        {
            if(did[i]||h[i]>ch||t[i]!=p) continue;
            if(m[i]>maxh) maxh=m[i],maxs=i;
        }
        if(maxs==0) break;
        did[maxs]=1; ch+=m[maxs]; rp++;
    }
    ans=max(ans,rp);
    cout<<ans;
}