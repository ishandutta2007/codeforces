#include <stdio.h>
#include <vector>
using namespace std;
const int N=200050;
const int M=2*N;
struct DSU
{
	int p[M],r[M];
	DSU()
	{
		for(int i=0;i<N;i++) p[i]=i,r[i]=0;
	}
} d;
int Find(DSU &d, int x)
{
	if(d.p[x]!=x) d.p[x]=Find(d,d.p[x]);
	return d.p[x];
}
void Union(DSU &d, int x, int y)
{
	x=Find(d,x);
	y=Find(d,y);
	if(x==y) return;
	if(d.r[x]<d.r[y]) d.p[x]=y;
	if(d.r[y]<d.r[x]) d.p[y]=x;
	if(d.r[x]==d.r[y]) d.r[x]++,d.p[y]=x;
}
int p[M],ls[M],rs[M],clock,root,Tr[M];
bool Done[M];
void Build(int &c, int ss, int se)
{
	c=++clock;
	if(ss==se)
	{
		Tr[ss]=c;
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Consider(int c, int ss, int se)
{
	if(Done[c]) return;
	Done[c]=true;
	if(ss!=se)
	{
		Union(d,c,ls[c]);
		Union(d,c,rs[c]);
		int mid=ss+se>>1;
		Consider(ls[c],ss,mid);
		Consider(rs[c],mid+1,se);
	}
}
vector<int> ToMerge;
void Merge(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		ToMerge.push_back(c);
		Consider(c,ss,se);
		return;
	}
	int mid=ss+se>>1;
	Merge(ls[c],ss,mid,qs,qe);
	Merge(rs[c],mid+1,se,qs,qe);
}
void Merge(int qs, int qe)
{
	ToMerge.clear();
	Merge(root,1,N,qs,qe);
	for(int i=1;i<ToMerge.size();i++) Union(d,ToMerge[i-1],ToMerge[i]);
}
int main()
{
	int n,q,i,t,x,y;
	scanf("%i %i",&n,&q);
	for(i=0;i<M;i++) d.p[i]=i,d.r[i]=0;
	Build(root,1,N);
	while(q--)
	{
		scanf("%i %i %i",&t,&x,&y);
		if(t==1) Union(d,Tr[x],Tr[y]);
		if(t==2) Merge(x,y);
		if(t==3)
		{
			x=Find(d,Tr[x]);
			y=Find(d,Tr[y]);
			if(x==y) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}