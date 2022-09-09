#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=200050;
int p[N],r[N];
int Extra[N];
bool Done[N];
int max(int a, int b){ return a>b?a:b;}
int Find(int x)
{
	if(p[x]!=x) p[x]=Find(p[x]);
	return p[x];
}
void Union(int x, int y)
{
	p[y]=x;Done[x]|=Done[y];
	//x=Find(x);
	//y=Find(y);
	//if(r[x]>r[y]) p[y]=x,Done[y]|=Done[x];//,Extra[y]=max(Extra[y],Extra[x]);
	//if(r[y]>r[x]) p[x]=y,Done[x]|=Done[y];//,Extra[x]=max(Extra[y],Extra[x]);
	//if(r[x]==r[y]) r[x]++,p[y]=x,Done[y]|=Done[x];//,Extra[x]=max(Extra[y],Extra[x]);
}
struct Edge
{
	int u,v,w;
	Edge(){}
	Edge(int a, int b, int c){ u=a,v=b,w=c;}
	bool operator < (Edge b) const
	{
		return w>b.w;
	}
} E[N];
int main()
{
	int n,m,i,sum=0;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) p[i]=i;
	for(i=1;i<=m;i++)
	{
		scanf("%i %i %i",&E[i].u,&E[i].v,&E[i].w);
	}
	sort(E+1,E+1+m);
	for(i=1;i<=m;i++)
	{
		int u=E[i].u;
		int v=E[i].v;
		int w=E[i].w;
		u=Find(u);
		v=Find(v);
		if(Done[u] && Done[v]) continue;
		if(u==v) Done[u]=1;
		else Union(u,v);
		sum+=w;
	}
	//for(i=1;i<=n;i++)
	//{
	//	if(p[i]==i) sum+=Extra[i];
	//}
	printf("%i\n",sum);
	return 0;
}