#include<stdio.h>
#include<vector>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
struct N
{
	int l,r,w,s;
}t[300020];
vector<int>a[100020];
vector<int>c[100020];
int p[100020];
int q[100020];
int L[100020];
int R[100020];
int s[100020],ss;
int z[100020];
int n,m,x,y;
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
	t[x].l=l,t[x].r=r;
	if(l==r)
		return;
	int m=l+r>>1;
	bd(x*2,l,m);
	bd(x*2+1,m+1,r);
	ud(x);
}
void cg(int x,int l,int r,int d)
{
	if(t[x].l>r||t[x].r<l)
		;
	else if(l<=t[x].l&&t[x].r<=r)
		t[x].w+=d;
	else
		cg(x*2,l,r,d),cg(x*2+1,l,r,d);
	ud(x);
}
void dfs(int x,int y)
{
	L[x]=++ss;
	fe(i,a[x])
		if(*i!=y)
			dfs(*i,x);
	R[x]=ss;
}
void DFS(int x,int y)
{
	fe(i,c[x])
		cg(1,L[p[*i]],R[p[*i]],1),cg(1,L[q[*i]],R[q[*i]],1);
	z[x]=t[1].s;
	fe(i,a[x])
		if(*i!=y)
			DFS(*i,x);
	fe(i,c[x])
		cg(1,L[p[*i]],R[p[*i]],-1),cg(1,L[q[*i]],R[q[*i]],-1);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,0);
	bd(1,1,n);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",p+i,q+i);
		c[p[i]].push_back(i);
		c[q[i]].push_back(i);
	}
	DFS(1,0);
	for(int i=1;i<=n;i++)
		printf("%d ",max(z[i]-1,0));
	return 0;
}