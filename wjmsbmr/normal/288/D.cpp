#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 100010
int he[N],ne[N*2],ad[N*2],fa[N],q[N],n,s[N];ll f[N],fs[N];
void add(int x,int y)
{
    static int t=0;
    ++t,ne[t]=he[x],he[x]=t,ad[t]=y,
    ++t,ne[t]=he[y],he[y]=t,ad[t]=x;
}
int main()
{
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++)
        scanf("%d%d",&x,&y),add(x,y);
    int le=1,ri=1;q[1]=1;
    while(le<=ri)
    {
        int x=q[le++];
        for(int p=he[x];p;p=ne[p])
            if(ad[p]!=fa[x])fa[ad[p]]=x,q[++ri]=ad[p];
    }
    for(int i=n;i>=1;i--)
    {
        int x=q[i];
        s[x]++;
        if(fa[x])s[fa[x]]+=s[x];
    }
    for(int i=1;i<=n;i++)
    {
        ll S=0;
        for(int p=he[i];p;p=ne[p])if(ad[p]!=fa[i])
            S+=(ll)s[ad[p]]*(s[i]-s[ad[p]]-1);
        f[i]=S/2+s[i]-1;
    }
    for(int i=n;i>=1;i--)
    {
        int x=q[i];
        fs[x]+=f[x]*s[x];
        if(fa[x])fs[fa[x]]+=fs[x];
    }
    ll T=0;
    for(int i=1;i<=n;i++)T+=f[i];
    T*=T;
    for(int i=1;i<=n;i++)T-=f[i]*f[i];
    ll S=0;
    for(int i=1;i<=n;i++)
    {
        for(int p=he[i];p;p=ne[p])if(ad[p]!=fa[i])
            S+=fs[ad[p]]*(s[i]-s[ad[p]]);
    }
    cout<<T-S*2<<endl;
    return 0;
}