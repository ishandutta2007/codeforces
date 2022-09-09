#include <bits/stdc++.h>
using namespace std;
#define ldb long double
const int N=100050;
const int M=2*N;
struct Node
{
	ldb l,r;
	Node(ldb p=0){ l=p;r=1-p;}
};
ldb Merge(ldb a, ldb b, ldb c, ldb d)
{
	ldb ans=a*(1/(1-c*b))*d;
	return ans;
}
Node operator + (Node a, Node b)
{
	Node c;
	c.l=Merge(a.l,1-a.r,1-b.l,b.l);
	c.r=Merge(b.r,1-b.l,1-a.r,a.r);
	return c;
}
int ls[M],rs[M],tsz,root;
Node node[M];
void Set(int &c, int ss, int se, int qi, ldb p)
{
	if(!c) c=++tsz;
	node[c]=Node(p);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,p);
	else Set(rs[c],mid+1,se,qi,p);
	node[c]=node[ls[c]]+node[rs[c]];
}
Node Get(int c, int ss, int se, int qs, int qe)
{
	if(qs<=ss && qe>=se) return node[c];
	int mid=ss+se>>1;
	if(qe<=mid) return Get(ls[c],ss,mid,qs,qe);
	if(qs>mid) return Get(rs[c],mid+1,se,qs,qe);
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
    int n,q,i,a,b,t,l,r;
    scanf("%i %i",&n,&q);
    for(i=1;i<=n;i++) scanf("%i %i",&a,&b),Set(root,1,n,i,(ldb)a/b);
    while(q--)
	{
		scanf("%i",&t);
		if(t==1) scanf("%i %i %i",&i,&a,&b),Set(root,1,n,i,(ldb)a/b);
		else scanf("%i %i",&l,&r),printf("%.12f\n",(double)Get(root,1,n,l,r).l);
	}
	return 0;
}