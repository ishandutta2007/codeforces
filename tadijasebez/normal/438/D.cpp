#include <stdio.h>
#define ll long long
int max(int a, int b){ return a>b?a:b;}
const int N=1<<17;
const int M=N*2;
struct Node
{
	ll Sum;
	int Max,Ind;
	Node(){ Sum=0,Max=-1,Ind=-1;}
	Node(ll a, int b, int c){ Sum=a,Max=b,Ind=c;}
	inline Node operator + (const Node &b) const
	{
		Node c;
		c.Sum=Sum+b.Sum;
		if(Max>b.Max) c.Ind=Ind;
		else c.Ind=b.Ind;
		c.Max=max(Max,b.Max);
		return c;
	}
} x[M];
void Init()
{
	for(int i=0;i<M;i++) x[i]=Node();
}
void Set(int i, int val)
{
	i+=N;
	x[i]=Node(val,val,i-N);
	for(i>>=1;i;i>>=1) x[i]=x[i+i]+x[i+i+1];
}
Node Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return Node(0,-1,-1);
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(c+c,ss,mid,qs,qe)+Get(c+c+1,mid+1,se,qs,qe);
}
int main()
{
	int n,q,t,l,r,k,mod,i,x;
	scanf("%i %i",&n,&q);
	Init();
	for(i=1;i<=n;i++) scanf("%i",&x),Set(i,x);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i",&l,&r);
			printf("%lld\n",Get(1,0,N-1,l,r).Sum);
		}
		if(t==2)
		{
			scanf("%i %i %i",&l,&r,&mod);
			Node tmp=Get(1,0,N-1,l,r);
			while(tmp.Max>=mod)
			{
				Set(tmp.Ind,tmp.Max%mod);
				tmp=Get(1,0,N-1,l,r);
			}
		}
		if(t==3)
		{
			scanf("%i %i",&k,&x);
			Set(k,x);
		}
	}
	return 0;
}