#include <stdio.h>
const int N=100050;
const int M=2*N;
double x[M],Lazy1[M],Lazy2[M],a[M];
int ls[M],rs[M],clock,root;
void Build(int &c, int ss, int se)
{
	c=++clock;Lazy1[c]=1;
	if(ss==se){ x[c]=a[ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=x[ls[c]]+x[rs[c]];
}
void Propagate(int c, int ss, int se)
{
	x[c]*=Lazy1[c];
	x[c]+=Lazy2[c]*(se-ss+1);
	if(ss!=se)
	{
		Lazy1[ls[c]]*=Lazy1[c];
		Lazy2[ls[c]]=Lazy2[c]+Lazy2[ls[c]]*Lazy1[c];
		Lazy1[rs[c]]*=Lazy1[c];
		Lazy2[rs[c]]=Lazy2[c]+Lazy2[rs[c]]*Lazy1[c];
	}
	Lazy1[c]=1;
	Lazy2[c]=0;
}
void Set(int c, int ss, int se, int qs, int qe, double X, double val)
{
	Propagate(c,ss,se);
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		Lazy1[c]*=X;
		Lazy2[c]+=val;
		Propagate(c,ss,se);
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,X,val);
	Set(rs[c],mid+1,se,qs,qe,X,val);
	x[c]=x[ls[c]]+x[rs[c]];
}
double Get(int c, int ss, int se, int qs, int qe)
{
	Propagate(c,ss,se);
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
	int n,q,i,X,t,l1,r1,l2,r2,l,r;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&X);
		a[i]=(double) X;
	}
	Build(root,1,N);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i %i %i",&l1,&r1,&l2,&r2);
			double sum1=Get(root,1,N,l1,r1)/(r1-l1+1);
			double sum2=Get(root,1,N,l2,r2)/(r2-l2+1);
			Set(root,1,N,l1,r1,double(r1-l1)/(r1-l1+1),sum2/(r1-l1+1));
			Set(root,1,N,l2,r2,double(r2-l2)/(r2-l2+1),sum1/(r2-l2+1));
		}
		else
		{
			scanf("%i %i",&l,&r);
			double ans=Get(root,1,N,l,r);
			printf("%.12llf\n",ans);
		}
	}
	return 0;
}