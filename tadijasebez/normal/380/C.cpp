#include <stdio.h>
#include <cstring>
const int N=1000050;
const int M=N*2;
int min(int a, int b){return a>b?b:a;}
struct Node
{
	int l,r,sol;
	Node(){l=0,r=0,sol=0;}
	Node(int a, int b, int c){l=a,r=b,sol=c;}
	inline Node operator + (const Node &b) const
	{
		Node c;
		int tmp=min(r,b.l);
		c.sol=sol+b.sol+2*tmp;
		c.l=l+b.l-tmp;
		c.r=r+b.r-tmp;
		return c;
	}
} x[M];
int ls[M],rs[M],clock,root;
char word[N];
void Build(int &c, int ss, int se)
{
	c=++clock;
	if(ss==se)
	{
		if(word[ss]=='(') x[c]=Node(0,1,0);
		else x[c]=Node(1,0,0);
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=x[ls[c]]+x[rs[c]];
}
Node Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return Node();
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
	int n,q,l,r;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	Build(root,0,n-1);
	scanf("%i",&q);
	while(q--) scanf("%i %i",&l,&r),printf("%i\n",Get(root,0,n-1,l-1,r-1).sol);
	return 0;
}