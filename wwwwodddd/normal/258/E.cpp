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
struct N
{
	int l,r,w;
	int s;
}t[300020];
vector<int>a[100020];
vector<int>c[100020];
int cl[100020][2];
int L[100020];
int R[100020];
int s[100020],ss;
int n,m;
int z[100020];
void ud(int x)
{
	if(t[x].w)
		t[x].s=t[x].r-t[x].l+1;
	else if(t[x].l!=t[x].r)
		t[x].s=t[x*2].s+t[x*2+1].s;
	else
		t[x].s=0;
}
void bd(int x,int l,int r)
{
	t[x].l=l;
	t[x].r=r;
	if(l==r)
	{
		return;
	}
	int m=l+r>>1;
	bd(x*2,l,m);
	bd(x*2+1,m+1,r);
	ud(x);
}
void cg(int x,int l,int r)
{
	if(t[x].l>r||t[x].r<l)
		return;
	if(l<=t[x].l&&t[x].r<=r)
	{
		t[x].w++;
		ud(x);
		return;
	}
	cg(x*2,l,r);
	cg(x*2+1,l,r);
	ud(x);
}
void del(int x,int l,int r)
{
	if(t[x].l>r||t[x].r<l)
		return;
	if(l<=t[x].l&&t[x].r<=r)
	{
		t[x].w--;
		ud(x);
		return;
	}
	del(x*2,l,r);
	del(x*2+1,l,r);
	ud(x);
}
void dfs(int x,int y)
{
	s[++ss]=x;
	L[x]=ss;
	fe(i,a[x])
		if(*i!=y)
			dfs(*i,x);
	R[x]=ss;
}
void DFS(int x,int y)
{
	fe(i,c[x])
	{
		cg(1,L[cl[*i][0]],R[cl[*i][0]]);
		cg(1,L[cl[*i][1]],R[cl[*i][1]]);
	}
	z[x]=t[1].s;
	fe(i,a[x])
		if(*i!=y)
			DFS(*i,x);
	fe(i,c[x])
	{
		del(1,L[cl[*i][0]],R[cl[*i][0]]);
		del(1,L[cl[*i][1]],R[cl[*i][1]]);
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,0);
	bd(1,1,n);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		c[x].push_back(i);
		c[y].push_back(i);
		cl[i][0]=x;
		cl[i][1]=y;
	}
	DFS(1,0);
	for(int i=1;i<=n;i++)
		if(z[i])
			printf("%d ",z[i]-1);
		else
			printf("0 ");
	return 0;
}