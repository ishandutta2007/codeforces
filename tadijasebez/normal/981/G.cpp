#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define mp make_pair
#define ll long long
const int N=200050;
set<pair<int,int> > ord[N];
set<pair<int,int> >::iterator it;
void Cut(int x, int y)
{
	it=ord[y].lower_bound(mp(x,N));
	if(it==ord[y].begin()) return;
	it--;
	int l=it->first,r=it->second;
	if(r<x || x==l) return;
	ord[y].erase(mp(l,r));
	ord[y].insert(mp(l,x-1));
	ord[y].insert(mp(x,r));
}
void Split(int l, int r, int y){ Cut(l,y);Cut(r+1,y);}
const int mod=998244353;
const int M=2*N;
int sum[M],lzy1[M],lzy2[M],ls[M],rs[M],tsz,root;
void Build(int &c, int ss, int se)
{
	c=++tsz;lzy1[c]=sum[c]=0;lzy2[c]=1;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Push(int c, int ss, int se)
{
	if(lzy1[c]==0 && lzy2[c]==1) return;
	sum[c]=(ll)sum[c]*lzy2[c]%mod;
	sum[c]+=(ll)lzy1[c]*(se-ss+1)%mod;
	if(sum[c]>=mod) sum[c]-=mod;
	if(ss!=se)
	{
		lzy2[ls[c]]=(ll)lzy2[ls[c]]*lzy2[c]%mod;
		lzy1[ls[c]]=(ll)lzy1[ls[c]]*lzy2[c]%mod;
		lzy1[ls[c]]+=lzy1[c];
		if(lzy1[ls[c]]>=mod) lzy1[ls[c]]-=mod;
		lzy2[rs[c]]=(ll)lzy2[rs[c]]*lzy2[c]%mod;
		lzy1[rs[c]]=(ll)lzy1[rs[c]]*lzy2[c]%mod;
		lzy1[rs[c]]+=lzy1[c];
		if(lzy1[rs[c]]>=mod) lzy1[rs[c]]-=mod;
	}
	lzy1[c]=0;
	lzy2[c]=1;
}
void Add(int c, int ss, int se, int qs, int qe)
{
	Push(c,ss,se);
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		lzy1[c]=1;
		Push(c,ss,se);
		return;
	}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe);
	Add(rs[c],mid+1,se,qs,qe);
	sum[c]=sum[ls[c]]+sum[rs[c]];
	if(sum[c]>=mod) sum[c]-=mod;
}
void Mul(int c, int ss, int se, int qs, int qe, int x)
{
	Push(c,ss,se);
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		lzy2[c]=x;
		Push(c,ss,se);
		return;
	}
	int mid=ss+se>>1;
	Mul(ls[c],ss,mid,qs,qe,x);
	Mul(rs[c],mid+1,se,qs,qe,x);
	sum[c]=sum[ls[c]]+sum[rs[c]];
	if(sum[c]>=mod) sum[c]-=mod;
}
int Get(int c, int ss, int se, int qs, int qe)
{
	Push(c,ss,se);
	if(qs<=ss && qe>=se) return sum[c];
	int mid=ss+se>>1,ret=0;
	if(mid>=qs) ret+=Get(ls[c],ss,mid,qs,qe);
	if(mid<qe) ret+=Get(rs[c],mid+1,se,qs,qe);
	if(ret>=mod) ret-=mod;
	return ret;
}
int main()
{
	int n,i,q,t,l,r,x;
	scanf("%i %i",&n,&q);
	Build(root,1,n);
	for(i=1;i<=n;i++) ord[i].insert(mp(1,n));
	while(q--)
	{
		scanf("%i %i %i",&t,&l,&r);
		if(t==1)
		{
			scanf("%i",&x);
			Mul(root,1,n,l,r,2);
			Split(l,r,x);
			for(it=ord[x].lower_bound(mp(l,0));it!=ord[x].upper_bound(mp(r,N));it++)
			{
				int qs=it->first,qe=it->second;
				Mul(root,1,n,qs,qe,mod+1>>1);
				Add(root,1,n,qs,qe);
			}
			ord[x].erase(ord[x].lower_bound(mp(l,0)),ord[x].upper_bound(mp(r,N)));
		}
		else
		{
			printf("%i\n",Get(root,1,n,l,r));
		}
	}
	return 0;
}