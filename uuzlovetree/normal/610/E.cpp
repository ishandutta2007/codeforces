#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,q,k;
char s[maxn];
int sumv[10][10][maxn<<2],tag[maxn<<2],c[maxn<<2];
void pushup(int rt)
{
	for(int i=0;i<k;++i)
		for(int j=0;j<k;++j)sumv[i][j][rt]=sumv[i][j][rt<<1]+sumv[i][j][rt<<1|1];
}
void clear(int rt)
{
	for(int i=0;i<k;++i)
		for(int j=0;j<k;++j)sumv[i][j][rt]=0; 
}
void pushdown(int rt,int l,int r)
{
	int mid=(l+r)>>1;
	if(tag[rt]!=-1)
	{
		int t=tag[rt];
		clear(rt<<1);clear(rt<<1|1);
		tag[rt<<1]=t;tag[rt<<1|1]=t;
		sumv[t][t][rt<<1]=mid-l+1;
		sumv[t][t][rt<<1|1]=r-mid;
		tag[rt]=-1;
	}
	if(c[rt]!=-1)
	{
		int t=c[rt];
		c[rt<<1]=t;c[rt<<1|1]=t;
		c[rt]=-1;
	}
}
void build(int rt,int l,int r)
{
	tag[rt]=c[rt]=-1;
	if(l==r)
	{
		if(l>1)sumv[s[l-1]-'a'][s[l]-'a'][rt]++;
		c[rt]=s[l]-'a';
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int pos,int v1,int v2)
{
	if(l==r)
	{
		clear(rt);
		sumv[v1][v2][rt]++;
		return;
	}
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	if(pos<=mid)update(rt<<1,l,mid,pos,v1,v2);
	else update(rt<<1|1,mid+1,r,pos,v1,v2);
	pushup(rt);
}
void cover(int rt,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr)
	{
		clear(rt);
		sumv[v][v][rt]=r-l+1;
		tag[rt]=v;
		return;
	}
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)cover(rt<<1,l,mid,ql,qr,v);
	if(qr>mid)cover(rt<<1|1,mid+1,r,ql,qr,v);
	pushup(rt);
}
int queryc(int rt,int l,int r,int pos)
{
	if(l==r)return c[rt];
	pushdown(rt,l,r);
	int mid=(l+r)>>1,ans=0;
	if(pos<=mid)ans=queryc(rt<<1,l,mid,pos);
	else ans=queryc(rt<<1|1,mid+1,r,pos);
	pushup(rt);
	return ans;
}
void setc(int rt,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr)
	{
		c[rt]=v;
		return;
	}
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)setc(rt<<1,l,mid,ql,qr,v);
	if(qr>mid)setc(rt<<1|1,mid+1,r,ql,qr,v);
	pushup(rt);
}
int main()
{
	scanf("%d%d%d",&n,&q,&k);
	scanf("%s",s+1);
	build(1,1,n);
	while(q--)
	{
		int op,l,r;
		char tmp[15];
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d%s",&l,&r,tmp);
			setc(1,1,n,l,r,tmp[0]-'a');
			if(r>l)cover(1,1,n,l+1,r,tmp[0]-'a');
			if(l>1)
			{
				int x=queryc(1,1,n,l-1);
				update(1,1,n,l,x,tmp[0]-'a');
			}
			if(r<n)
			{
				int x=queryc(1,1,n,r+1);
				update(1,1,n,r+1,tmp[0]-'a',x);
			}
		}
		else
		{
			scanf("%s",tmp);
			int ans=1;
			for(int i=0;i<k;++i)
				for(int j=i;j>=0;--j)
				{
					ans+=sumv[tmp[i]-'a'][tmp[j]-'a'][1];
				}
			printf("%d\n",ans);
		}
	}
}