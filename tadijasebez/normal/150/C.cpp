#include <stdio.h>
#define db double
const int N=150050;
const int M=2*N;
db max(db a, db b){ return a>b?a:b;}
struct Node
{
	db l,r,sum,best;
	Node(){}
	Node(db x){ l=r=best=max(x,0);sum=x;}
} node[M];
Node operator + (Node a, Node b)
{
	Node ans;
	ans.best=max(a.best,b.best);
	ans.best=max(ans.best,a.r+b.l);
	ans.sum=a.sum+b.sum;
	ans.l=max(a.l,a.sum+b.l);
	ans.r=max(b.r,b.sum+a.r);
	return ans;
}
db sub[N];
int ls[M],rs[M],tsz,root;
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se){ node[c]=Node(sub[ss]);return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
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
int x[N],p[N];
int main()
{
	int n,m,c,i,l,r;
	scanf("%i %i %i",&n,&m,&c);
	for(i=1;i<=n;i++) scanf("%i",&x[i]);
	for(i=2;i<=n;i++) scanf("%i",&p[i]),sub[i]=(db)(x[i]-x[i-1])/2-(db)c*p[i]/100;
	Build(root,2,n);
	db sol=0;
	while(m--)
	{
		scanf("%i %i",&l,&r);
		sol+=Get(root,2,n,l+1,r).best;
		Node tmp=Get(root,2,n,l+1,r);
		//printf("%llf %llf %llf %llf\n",tmp.l,tmp.r,tmp.sum,tmp.best);
	}
	printf("%.12llf\n",sol);
	return 0;
}