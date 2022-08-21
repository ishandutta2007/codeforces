//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n,a[1000001],v[1000001],need[1000001],childs[1000001],ct[1000001],ad=0,s,p;
void dfs(int now)
{
    if(now>s) return;
    if(now>=p)
    {
        childs[now]=a[now];
        return;
    }
    dfs(now*2); dfs(now*2+1);
    childs[now]=max(childs[now*2],childs[now*2+1])+a[now];
    //childs[now]=childs[now*2]+childs[now*2+1]+a[now];
}
int main()
{
    cin>>n;
    s=1<<(n+1); s--; p=1<<n;
    for(int i=2;i<=s;i++) cin>>a[i];
    for(int i=s+1;i<=s*3;i++) childs[i]=0;
    int maxl=0;
    for(int i=1;i<=s;i++)
    {
        int c=i; v[i]=a[i]; need[i]=0x7ffffff;
        while(c!=1) c>>=1, v[i]+=a[c];
        maxl=max(maxl,v[i]);
    }
    //for(int i=2;i<=s;i++) need[i]=maxl-v[i];
    //cout<<maxl<<"\n";
    dfs(1);
    int rps=0;
    for(int i=2;i<=s;i++)
    {
        //int s1=maxl-fuck[i/2]-childs[i*2],s2=maxl-fuck[i/2]-childs[i*2+1],rs=need[i];
        //int te=min(s1,rs); te=min(te,s2); te=max(te,0);
        int te=maxl-childs[i]-v[i/2]-ct[i/2];
        if(te<0) te=0;
        rps+=te;
        ct[i]=ct[i/2]+te;
        //cout<<te<<","<<i<<" "<<childs[i]<<"\n";
    }
    cout<<rps;
    return 0;
}