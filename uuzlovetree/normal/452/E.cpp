#include<bits/stdc++.h>
#define ll long long
#define maxn 600005
using namespace std;
int ch[maxn][26];
int fa[maxn],cnt,last,rt;
ll sz[maxn][3],dis[maxn];
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
void add(int x,int bel)
{
	int p=last;
    if(ch[p][x])
    {
        int q=ch[p][x];
        if(dis[q]==dis[p]+1)last=q;
        else
        {
            int nq=newnode(dis[p]+1);last=nq;
            memcpy(ch[nq],ch[q],sizeof(ch[q]));fa[nq]=fa[q];
            fa[q]=nq;
            for(;ch[p][x]==q;p=fa[p])ch[p][x]=nq;
        }
    }
    else
    {
        int np=newnode(dis[p]+1);last=np;
        for(;p&&(!ch[p][x]);p=fa[p])ch[p][x]=np;
        if(!p)fa[np]=rt;
        else
        {
            int q=ch[p][x];
            if(dis[q]==dis[p]+1)fa[np]=q;
            else
            {
                int nq=newnode(dis[p]+1);
                memcpy(ch[nq],ch[q],sizeof(ch[q]));fa[nq]=fa[q];
                fa[q]=fa[np]=nq;
                for(;ch[p][x]==q;p=fa[p])ch[p][x]=nq;
            }
        }
    }
    sz[last][bel]++;
}
char s[maxn];
int c[maxn],t[maxn];
const int mod = 1000000007;
char A[maxn],B[maxn],C[maxn];
ll sumt[maxn];
void update(int x,ll v)
{
	for(int i=x;i<=300000;i+=i&(-i))sumt[i]=(sumt[i]+v)%mod;
}
ll query(int x)
{
	ll ans=0;
	for(int i=x;i;i-=i&(-i))ans=(ans+sumt[i])%mod;
	return ans;
}
int main()
{
	init();
    scanf("%s",A+1);
    int lena=strlen(A+1);
    for(int i=1;i<=lena;++i)add(A[i]-'a',0);
    last=1;
    scanf("%s",B+1);
    int lenb=strlen(B+1);
    for(int i=1;i<=lenb;++i)add(B[i]-'a',1);
    last=1;
    scanf("%s",C+1);
    int lenc=strlen(C+1);
    for(int i=1;i<=lenc;++i)add(C[i]-'a',2);
    int n=min(min(lena,lenb),lenc);
    for(int i=1;i<=cnt;i++)c[dis[i]]++;
    for(int i=1;i<=cnt;i++)c[i]+=c[i-1];
    for(int i=cnt;i;i--)t[c[dis[i]]--]=i;
    for(int i=cnt;i;i--)
	{
		int x=t[i];
		for(int j=0;j<3;++j)sz[fa[x]][j]+=sz[x][j];
	}
	for(int i=1;i<=cnt;++i)
	{
		ll x=1ll*sz[i][0]*sz[i][1]%mod*sz[i][2]%mod;
		update(dis[fa[i]]+1,x);
		update(dis[i]+1,(mod-x)%mod);
	}
	for(int i=1;i<=n;++i)
	{
		printf("%lld%c",query(i),(i==n)?'\n':' ');
	}
}