#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int n,m,k,u,v,y,w[100020],d[100020],f[100020][18],s[100020],L[100020],R[100020],ss;
vector<int>a[100020];
int lca(int x,int y)
{
	if(d[x]>d[y])
		swap(x,y);
	for(int k=d[y]-d[x],i=18;i--;)
		if(k>>i&1)
			y=f[y][i];
	if(x==y)
		return x;
	for(int i=18;i--;)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
void dfs(int x)
{
	s[L[x]=ss++]=x;
	for(int i:a[x])
	{
		d[i]=d[x]+1;
		dfs(i);
	}
	R[x]=ss;
}
struct N
{
	N *l,*r;
	int s;
}t[5000020],*rt[100020],*tt=t;
N* bd(int l,int r)
{
	N *p=tt++;
	int m=l+r>>1;
	if(l!=r)
	{
		p->l=bd(l,m);
		p->r=bd(m+1,r);
	}
	return p;
}
N* cg(N *q,int l,int r,int x,int d)
{
	if(x>r)
		return q;
	N *p=tt++;
	*p=*q;
	p->s=q->s+d;
	if(l!=r)
	{
		int m=(l+r)>>1;
		if(x<=m)
			p->l=cg(q->l,l,m,x,d);
		else 
			p->r=cg(q->r,m+1,r,x,d);
	}
	return p;
}
int A(N *l,N *r,int x)
{
	int tl=1,tr=n,re=0;
	x=L[x];
	while(tl!=tr) 
	{
		int m=(tl+tr)>>1;
		if (x<=m)
			l=l->l,r=r->l,tr=m;
		else
			re+=r->l->s-l->l->s,l=l->r,r=r->r,tl=m+1;
	}
	return re+r->s-l->s;
}
int qy(int u,int x,int l,int r)
{
	x=d[u]-A(rt[l],rt[r],u)-x+1;
	for (int k=18;k--;)
		if(x<=d[f[u][k]]-A(rt[l],rt[r],f[u][k]))
			u=f[u][k];
	return u;
}
int Q(int x)
{
	return w[x]<=y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",f[i]),a[f[i][0]].push_back(i);
	for(int j=1;j<18;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	dfs(0);
	rt[0]=bd(1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d",&u),w[u]=i,
			rt[i]=cg(cg(rt[i-1],1,n,L[u],1),1,n,R[u],-1);
		}
		else
		{
			scanf("%d%d%d%d",&u,&v,&k,&y);
			rt[i]=rt[i-1];
			int p=lca(u,v),cu=d[u]-A(rt[y],rt[i],u),cv=d[v]-A(rt[y],rt[i],v),cp=d[p]-A(rt[y],rt[i],p);
			cu=cu-cp+Q(p);
			cv=cv-cp;
			if (k>cu+cv-Q(u)-Q(v))
				puts("-1");
			else if(k<=cu-Q(u))
				printf("%d\n",qy(u,k+Q(u),y,i));
			else
				printf("%d\n",qy(v,cv+cu-k-Q(u)+1,y,i));
		}
	}
	return 0;
}