#include<bits/stdc++.h>
#define ll long long
#define maxn 400005
using namespace std;
int ch[maxn][26];
int fa[maxn],cnt,last,rt;
ll sz[maxn],dis[maxn];
void init()
{
    cnt=0;
    rt=last=++cnt;
    memset(fa,0,sizeof(fa));
    memset(dis,0,sizeof(dis));
    memset(sz,0,sizeof(sz));
    memset(ch,0,sizeof(ch));
}
inline int newnode(int x){dis[++cnt]=x;return cnt;}
void add(int x,int delta)
{
    int np=newnode(dis[last]+1),p=last;
    for(;p&&(!ch[p][x]);p=fa[p])ch[p][x]=np;
    if(!p)fa[np]=rt;
    else
    {
        int q=ch[p][x];
        if(dis[q]==dis[p]+1)fa[np]=q;
        else
        {
            int nq=newnode(dis[p]+1);
            memcpy(ch[nq],ch[q],sizeof(ch[q]));
            fa[nq]=fa[q];
            fa[q]=fa[np]=nq;
            for(;ch[p][x]==q;p=fa[p])ch[p][x]=nq;
        }
    }
    last=np;
    sz[np]=delta;
}
int c[maxn],t[maxn];
void count()
{
    memset(c,0,sizeof(c));
    memset(t,0,sizeof(t));
    ll ans=0;
    for(int i=1;i<=cnt;i++)c[dis[i]]++;
    for(int i=1;i<=cnt;i++)c[i]+=c[i-1];
    for(int i=cnt;i;i--)t[c[dis[i]]--]=i;
    for(int i=cnt;i;i--){int x=t[i];sz[fa[x]]+=sz[x];}
    for(int i=1;i<=cnt;++i)ans=max(ans,1ll*dis[i]*sz[i]);
    printf("%lld\n",ans);
}
int n;
char s[maxn],a[maxn];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%s",a+1);
    init();
    for(int i=1;i<=n;++i)
	{
		int d=a[i]-'0';
		add(s[i]-'a',d^1);
	}
	count();
}