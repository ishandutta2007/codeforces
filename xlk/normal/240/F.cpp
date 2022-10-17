#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,m,mx;
struct N
{
	int l,r,s[26];
	int u;
}t[262626];
char s[100020];
int z[26];
void sa(int x,int u)
{
	memset(t[x].s,0,sizeof z);
	t[x].s[u]=t[x].r-t[x].l+1;
	t[x].u=u;
}
void pd(int x)
{
	if(t[x].l==t[x].r)
		return;
	if(t[x].u==-1)
		return;
	sa(x*2,t[x].u);
	sa(x*2+1,t[x].u);
	t[x].u=-1;
}
void mg(int *a,int *b,int *c)
{
	for(int i=0;i<26;i++)
		a[i]=b[i]+c[i];
}
void bd(int x,int l,int r)
{
	mx=max(mx,x);
	t[x].l=l;
	t[x].r=r;
	t[x].u=-1;
	if(l==r)
	{
		t[x].s[s[l]-'a']=1;
		return;
	}
	int m=l+r>>1;
	bd(x*2,l,m);
	bd(x*2+1,m+1,r);
	mg(t[x].s,t[x*2].s,t[x*2+1].s);
}
void qy(int x,int l,int r)
{
	if(t[x].l>r||t[x].r<l)
		return;
	pd(x);
	if(l<=t[x].l&&t[x].r<=r)
	{
		mg(z,z,t[x].s);
		return;
	}
	qy(x*2,l,r);
	qy(x*2+1,l,r);
}
void cg(int x,int l,int r,int u)
{
	if(t[x].l>r||t[x].r<l)
		return;
	pd(x);
	if(l<=t[x].l&&t[x].r<=r)
	{
		sa(x,u);
		return;
	}
	cg(x*2,l,r,u);
	cg(x*2+1,l,r,u);
	mg(t[x].s,t[x*2].s,t[x*2+1].s);
}
void pt(int x)
{
	if(t[x].l==t[x].r)
	{
		for(int i=0;i<26;i++)
			if(t[x].s[i]==1)
				printf("%c",i+'a');
		return;
	}
	pd(x);
	pt(x*2);
	pt(x*2+1);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	bd(1,1,n);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		memset(z,0,sizeof z);
		qy(1,x,y);
		int u=-1;
		for(int i=0;i<26;i++)
			if(z[i]&1)
			{
				if(u!=-1)
					goto end;
				u=i;
				z[i]--;
			}
		for(int i=0;i<26;i++)
		{
			z[i]/=2;
			if(!z[i])
				continue;
			cg(1,x,x+z[i]-1,i);
			cg(1,y-z[i]+1,y,i);
			x+=z[i];
			y-=z[i];
		}
		if(u!=-1)
			cg(1,x,y,u);
		end:;
	}
	pt(1);
	return 0;
}