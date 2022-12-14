#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <cstdlib>
using namespace std;
#define N 200005
char buf[1000000],*p1,*p2;
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++)
int rd()
{
	register int x=0;register char c=nc();
	while(c<'0'||c>'9')c=nc();
	while(c>='0'&&c<='9')x=(((x<<2)+x)<<1)+c-'0',c=nc();
	return x;
}
int fa[N],head[N],cnt,dep[N],num,s[N],t[N],vis[N],n,m,used[N<<1],tt[N],last,ff[N];
struct node
{
	int from,to,next;
}e[N<<1];
void add(int x,int y)
{
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt++;
	return ;
}
void dfs(int x,int from)
{
	fa[x]=from;
	vis[x]=1;
	dep[x]=dep[from]+1;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(!used[i])
		{
			used[i]=used[i^1]=1;
			if(vis[to1])
			{
				if(!((dep[x]-dep[to1])&1))
				{
					last=i;
					num++;
					s[x]++;
					s[to1]--;
				}else
				{
					t[x]++;
					t[to1]--;
				}
			}else
			{
				ff[to1]=i;
				dfs(to1,x);
				s[x]+=s[to1];
				t[x]+=t[to1];
			}
		}
	}
}
char pbuf[1000006],*pp=pbuf;
__attribute__((optimize("-O3")))void write(register int x) {
	static int sta[20];
	int top=0;
	do{sta[top++]=x%10,x/=10;}while(x);
	while(top) *pp++=sta[--top]+'0';
}
int main()
{
	// freopen("voltage.in","r",stdin);
	// freopen("voltage.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
	{
		x=rd(),y=rd();
		e[cnt]=(node){x,y,head[x]};head[x]=cnt++;
		e[cnt]=(node){y,x,head[y]};head[y]=cnt++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])dfs(i,0);
	}
	if(!num)
	{
		write(m);*pp++='\n';
		for(int i=1;i<=m;i++)write(i),*pp++=' ';
		fwrite(pbuf,1,pp-pbuf,stdout);return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(fa[i]&&s[i]==num&&!t[i])tt[++ans]=(ff[i]>>1)+1;
	if(num==1)tt[++ans]=(last>>1)+1;sort(tt+1,tt+ans+1);
	write(ans);*pp++='\n';
	for(int i=1;i<=ans;i++)write(tt[i]),*pp++=' ';
	fwrite(pbuf,1,pp-pbuf,stdout);return 0;
}