#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int fa[N],n,p;ll now,a[N];
int main()
{
    scanf("%d%lld",&n,&now);
    if(now*2>(ll)n*(n+1))return puts("No"),0;
    if(now<n*2-1)return puts("No"),0;
    for(p=1;p<=n;p++)
    {
        long long dep=1,cnt=1,t=1,c=1;
        while(cnt<n)c=c*p,dep++,t+=dep*min(c,n-cnt),cnt+=c;
        if(t<=now)break;
    }
    puts("Yes");
    long long dep=1,cnt=1,t=1,c=1;a[1]=1;
    while(cnt<n)
    {
        dep++;c=c*p;a[dep]=min(c,n-cnt);
        t+=dep*min(c,n-cnt),cnt+=c;
    }now-=t;
    long long now_d=dep,aft_d=dep+1;
    while(now)
    {
        if(a[now_d]<=1)now_d--;
        a[now_d]--;ll tmp=min(aft_d++,now_d+now);
        now-=tmp-now_d;a[tmp]++;
    }
    int lst=1;
    for(int i=2;i<aft_d;i++)
    {
        int nowp=lst-a[i-1]+1,nowk=0;
        // printf("%lld\n",a[i]);
        for(int j=lst+1;j<=lst+a[i];j++)
        {
            if(nowk==p)nowp++,nowk=0;
            nowk++,fa[j]=nowp;
        }lst+=a[i];
    }
    for(int i=2;i<=n;i++)printf("%d ",fa[i]);puts("");
}
//sdadasdasd