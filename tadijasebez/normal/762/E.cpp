#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <ctime>
using namespace std;
#define ll long long
const int N=100050;
int ls[N],rs[N],sz[N],L[N],R[N],x[N],y[N],root[N],tsz;
int MakeNode(int X)
{
	tsz++;
	L[tsz]=R[tsz]=x[tsz]=X;
	sz[tsz]=1;
	y[tsz]=rand();
	return tsz;
}
void Pull(int c)
{
	if(!c) return;
	L[c]=R[c]=x[c];
	sz[c]=sz[ls[c]]+sz[rs[c]]+1;
	if(ls[c]) L[c]=L[ls[c]];
	if(rs[c]) R[c]=R[rs[c]];
}
void Rotate1(int &c)
{
	int a=ls[c],b=rs[a];
	ls[c]=b;
	rs[a]=c;
	Pull(c);Pull(a);
	c=a;
}
void Rotate2(int &c)
{
	int a=rs[c],b=ls[a];
	rs[c]=b;
	ls[a]=c;
	Pull(c);Pull(a);
	c=a;
}
void Add(int &c, int X)
{
	//printf("%i %i\n",c,x[c]);
	if(!c){ c=MakeNode(X);return;}
	if(x[c]<X)
	{
		Add(rs[c],X);
		if(y[rs[c]]>y[c]) Rotate2(c);
	}
	else
	{
		Add(ls[c],X);
		if(y[ls[c]]>y[c]) Rotate1(c);
	}
	Pull(c);
}
void Del(int &c, int X)
{
	if(!c) return;
	if(x[c]==X)
	{
		if(!ls[c]) c=rs[c];
		else if(!rs[c]) c=ls[c];
		else if(y[ls[c]]>y[rs[c]]) Rotate1(c),Del(rs[c],X);
		else Rotate2(c),Del(ls[c],X);
		Pull(c);
		return;
	}
	if(x[c]<X) Del(rs[c],X);
	else Del(ls[c],X);
	Pull(c);
}
int Get(int c, int qs, int qe)
{
	if(!c || L[c]>qe || R[c]<qs) return 0;
	if(qs<=L[c] && qe>=R[c]) return sz[c];
	int ans=0;
	if(qs<=x[c] && qe>=x[c]) ans++;
	ans+=Get(ls[c],qs,qe);
	ans+=Get(rs[c],qs,qe);
	return ans;
}
void Print(int c)
{
	if(!c) return;
	Print(ls[c]);
	printf("%i ",x[c]);
	Print(rs[c]);
}
int a[N],r[N],f[N],id[N];
bool comp(int i, int j){ return r[i]<r[j];}
int main()
{
	srand(time(0));
	int n,i,k,l;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i %i %i",&a[i],&r[i],&f[i]),id[i]=i,Add(root[f[i]],a[i]);
	sort(id+1,id+1+n,comp);
	ll sol=0;
	//for(l=1;l<=4;l++)
	//{
		//printf("f=%i | ",l);
		//Print(root[l]);
		//printf("\n");
	//}
	for(i=1;i<=n;i++)
	{
		int j=id[i];
		Del(root[f[j]],a[j]);
		ll add=0;
		for(l=f[j]-k;l<=f[j]+k;l++)
		{
			if(l<0) continue;
			add+=Get(root[l],a[j]-r[j],a[j]+r[j]);
		}
		//printf("%i %lld\n",j,add);
		sol+=add;
		//for(l=1;l<=4;l++)
		//{
			//printf("f=%i | ",l);
			//Print(root[l]);
			//printf("\n");
		//}
	}
	printf("%lld\n",sol);
	return 0;
}