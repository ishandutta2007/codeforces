#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define pb push_back
const int N=100050;
const int S=200;
const int M=N*S;
int max(int a, int b){ return a>b?a:b;}
struct Node
{
	int l,r,sz,val;
	Node(){}
	Node(int a, int b, int c, int d){ l=a,r=b,sz=c,val=d;}
	Node operator + (Node b) const
	{
		Node c;
		c.sz=sz+b.sz;
		c.val=max(val,b.val);
		c.val=max(c.val,r+b.l);
		c.l=l;
		if(l==sz) c.l+=b.l;
		c.r=b.r;
		if(b.r==b.sz) c.r+=r;
		return c;
	}
} node[M];
int ls[M],rs[M],tsz,root[N];
void Set(int &c, int ss, int se, int qi, int f)
{
	if(!c) c=++tsz;
	if(ss==se){ node[c].l=node[c].r=node[c].val=f;node[c].sz=1;return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,f);
	else Set(rs[c],mid+1,se,qi,f);
	if(!ls[c]) node[c]=node[rs[c]],node[c].l=0,node[c].sz+=mid-ss+1;
	else if(!rs[c]) node[c]=node[ls[c]],node[c].r=0,node[c].sz+=se-mid;
	else node[c]=node[ls[c]]+node[rs[c]];
}
Node Get(int c, int ss, int se, int qs, int qe)
{
	if(!c) return Node(0,0,se-ss+1,0);
	if(qs<=ss && qe>=se) return node[c];
	int mid=ss+se>>1;
	if(mid<qs) return Get(rs[c],mid+1,se,qs,qe);
	else if(mid+1>qe) return Get(ls[c],ss,mid,qs,qe);
	else return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
struct RMQ
{
	int rmq[1<<18];
	RMQ(){}
	void Set(int x, int val){ x+=1<<17;rmq[x]=val;for(x>>=1;x;x>>=1) rmq[x]=max(rmq[x<<1],rmq[x<<1|1]);}
	int Get(int l, int r)
	{
		l+=1<<17;r+=1<<17;
		int ret=0;
		for(;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ret=max(ret,rmq[l++]);
			if(r%2==0) ret=max(ret,rmq[r--]);
		}
		return ret;
	}
} Tree;
string s[N];
int GetLCP(int x, int y)
{
	int k=0;
	while(k<s[x].size() && k<s[y].size() && s[x][k]==s[y][k]) k++;
	return k;
}
vector<int> ids;
struct Query
{
	int t,a,b,x,sz,l,r;
	Query(){}
} Q[N];
int a[N],b[N];
int main()
{
	int n,q,i,j,t,l,r,x;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) cin >> s[i],Tree.Set(i,s[i].size());
	for(i=1;i<n;i++) a[i]=b[i]=GetLCP(i,i+1),ids.pb(a[i]);
	for(i=1;i<=q;i++)
	{
		scanf("%i",&Q[i].t);
		if(Q[i].t==1) scanf("%i %i",&Q[i].l,&Q[i].r);
		else
		{
			scanf("%i",&Q[i].x);
			cin >> s[Q[i].x];
			if(Q[i].x<n) Q[i].a=GetLCP(Q[i].x,Q[i].x+1),ids.pb(Q[i].a);
			if(Q[i].x>1) Q[i].b=GetLCP(Q[i].x-1,Q[i].x),ids.pb(Q[i].b);
			Q[i].sz=s[Q[i].x].size();
		}
	}
	sort(ids.begin(),ids.end());
	ids.erase(unique(ids.begin(),ids.end()),ids.end());
	for(i=1;i<n;i++)
	{
		for(j=0;j<ids.size() && a[i]>=ids[j];j++) Set(root[j],1,n-1,i,1);
	}
	for(i=1;i<=q;i++)
	{
		if(Q[i].t==1)
		{
			l=Q[i].l;r=Q[i].r;
			int sol=Tree.Get(l,r);
			for(j=0;j<ids.size();j++)
			{
				int val=Get(root[j],1,n-1,l,r-1).val;
				if(val) sol=max(sol,ids[j]*(val+1));
			}
			printf("%i\n",sol);
		}
		else
		{
			x=Q[i].x;Tree.Set(x,Q[i].sz);
			if(x<n)
			{
				for(j=0;j<ids.size() && a[x]>=ids[j];j++) Set(root[j],1,n-1,x,0);
				a[x]=Q[i].a;
				for(j=0;j<ids.size() && a[x]>=ids[j];j++) Set(root[j],1,n-1,x,1);
			}
			if(x>1)
			{
				x--;
				for(j=0;j<ids.size() && a[x]>=ids[j];j++) Set(root[j],1,n-1,x,0);
				a[x]=Q[i].b;
				for(j=0;j<ids.size() && a[x]>=ids[j];j++) Set(root[j],1,n-1,x,1);
			}
		}
	}
	return 0;
}