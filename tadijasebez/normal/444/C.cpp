#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
#define ll long long
const int N=100050;
const int M=2*N;
int abs(int x){ return x>0?x:-x;}
ll x[M],y[M];
int ls[M],rs[M],clock,root;
void Build(int &c, int ss, int se)
{
	c=++clock;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Propagate(int c, int ss, int se)
{
	if(!y[c]) return;
	x[c]+=y[c]*(se-ss+1);
	if(ss!=se)
	{
		y[ls[c]]+=y[c];
		y[rs[c]]+=y[c];
	}
	y[c]=0;
}
void Set1(int c, int ss, int se, int qs, int qe, int X)
{
	Propagate(c,ss,se);
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		y[c]+=X;
		Propagate(c,ss,se);
		return;
	}
	int mid=ss+se>>1;
	Set1(ls[c],ss,mid,qs,qe,X);
	Set1(rs[c],mid+1,se,qs,qe,X);
	x[c]=x[ls[c]]+x[rs[c]];
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	Propagate(c,ss,se);
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
struct Seg
{
	int l,r,c;
	Seg(){}
	Seg(int a, int b, int e){ l=a,r=b,c=e;}
	bool operator < (Seg b) const
	{
		if(l==b.l) return r<b.r;
		return l<b.l;
	}
};
set<Seg> Set;
set<Seg>::iterator it;
void Cut(int i)
{
	if(!i) return;
	it=Set.upper_bound(Seg(i,M,0));
	it--;
	Seg tmp=*it;
	if(tmp.r>i)
	{
		Set.erase(tmp);
		Set.insert(Seg(tmp.l,i,tmp.c));
		Set.insert(Seg(i+1,tmp.r,tmp.c));
	}
}
vector<Seg> v;
void Take(int l, int r)
{
	Cut(l-1);
	Cut(r);
	v.clear();
	for(it=Set.lower_bound(Seg(l,0,0));it!=Set.upper_bound(Seg(r,M,0));it++)
	{
		v.push_back(*it);
	}
	Set.erase(Set.lower_bound(Seg(l,0,0)),Set.upper_bound(Seg(r,M,0)));
}
int main()
{
	int n,q,i,t,l,r,x;
	scanf("%i %i",&n,&q);
	Build(root,1,n);
	for(i=1;i<=n;i++) Set.insert(Seg(i,i,i));
	while(q--)
	{
		scanf("%i %i %i",&t,&l,&r);
		if(t==1)
		{
			scanf("%i",&x);
			Take(l,r);
			for(i=0;i<v.size();i++)
			{
				Set1(root,1,n,v[i].l,v[i].r,abs(v[i].c-x));
			}
			Set.insert(Seg(l,r,x));
		}
		else
		{
			printf("%lld\n",Get(root,1,n,l,r));
		}
	}
	return 0;
}