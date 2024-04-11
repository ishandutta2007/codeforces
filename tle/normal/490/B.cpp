//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n,a[300000],b[300000],next[1000010],prev[1000010],bg,ans[300000];
bool doit[300000];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        prev[b[i]]=i;
        next[a[i]]=i;
        if(a[i]==0) bg=i;
    }
    int now=bg,cn=0;
    while(now!=0&&!doit[now])
    {
        doit[now]=1;
        cn++;
        ans[cn*2-2]=a[now];
        ans[cn*2]=b[now];
        now=next[b[now]];
    }
    //cout<<"!\n";
    int now2=0;
    for(int i=1;i<=n;i++)
    {
        if(!doit[i]) {now2=i; break;}
    }
    while(prev[a[now2]]!=0) now2=prev[a[now2]];
    cn=0;
    while(now2!=0&&!doit[now2])
    {
        doit[now2]=1;
        cn++;
        ans[cn*2-1]=a[now2];
        ans[cn*2+1]=b[now2];
        //cout<<now2<<"\n";
        now2=next[b[now2]];
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}