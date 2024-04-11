#include<stdio.h>
#include<string.h>
#include<iostream>
#define inf 0x3f3f3f3f
using namespace std;
int e[200020][4];
int h[5010];
int d[5010];
int v[5010];
int p[5010];
int l[200020];
int q[200020],bb,ff;
int n,m,s,t,flw;
int csc,ans,tot;
void add(int x,int y,int z,int w)
{
	tot++;
	e[tot][0]=h[x];
	e[tot][1]=y;
	e[tot][2]=z;
	e[tot][3]=w;
	h[x]=tot;

	tot++;
	e[tot][0]=h[y];
	e[tot][1]=x;
	e[tot][2]=0;
	e[tot][3]=-w;
	h[y]=tot;
}
int spfa()
{
	int i,u;
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	bb=ff=0;
	q[ff++]=s;
	d[s]=0;
	v[s]=1;
	while(bb<ff)
	{
		u=q[bb++];
		v[u]=0;
		for(i=h[u];i;i=e[i][0])
			if(e[i][2]&&d[e[i][1]]>d[u]+e[i][3])
			{
				d[e[i][1]]=d[u]+e[i][3];
				p[e[i][1]]=i;
				if(!v[e[i][1]])
				{
					q[ff++]=e[i][1];
					v[e[i][1]]=1;
				}
			}
	}
	return d[t]!=0x3f3f3f3f;
}
void ek()
{
	int i,a=inf;
	for(i=t;i!=s;i=e[p[i]^1][1])
		a=min(a,e[p[i]][2]);
	for(i=t;i!=s;i=e[p[i]^1][1])
		e[p[i]][2]-=a,e[p[i]^1][2]+=a;
	ans+=d[t]*a;
	flw+=a;
}
char ss[120];
int cc[30];
int main()
{
	int i,j,k,w,len;
	tot=1;
	scanf("%s",ss);
	len=strlen(ss);
	for(int i=0;ss[i];i++)
		cc[ss[i]-'a']++;
	scanf("%d",&n);
	s=n+26;
	t=s+1;
	for(int i=0;i<26;i++)
		add(n+i,t,cc[i],0);
	for(i=0;i<n;i++)
	{
		scanf("%s",ss);
		memset(cc,0,sizeof cc);
		for(int j=0;ss[j];j++)
			cc[ss[j]-'a']++;
		int x;
		scanf("%d",&x);
		add(s,i,x,0);
		for(int j=0;j<26;j++)
			add(i,n+j,cc[j],i+1);
	}
	while(spfa())
		ek();
	if(flw<len)
		puts("-1");
	else
		printf("%d\n",ans);
	return 0;
}