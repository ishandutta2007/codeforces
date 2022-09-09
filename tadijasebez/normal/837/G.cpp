#include <stdio.h>
const int N=200001;
const int M=20000050;
int clock,r[M],l[M],root[N];
long long a[M],b[M],A,B;
void Set(int prev, int &cur, int ss, int se, int qs, int qe, int u, int v)
{
	cur=++clock;
	l[cur]=l[prev];
                                             r[cur]=r[prev];
	a[cur]=a[prev];
	b[cur]=b[prev];
	if(qs<=ss && qe>=se)
	{
		a[cur]+=u;
		b[cur]+=v;
		return;
	}
	int mid=(ss+se)>>1;
	if(qs<=mid) Set(l[prev],l[cur],ss,mid,qs,qe,u,v);
	if(qe>mid) Set(r[prev],r[cur],mid+1,se,qs,qe,u,v);
}
void Get(int cur, int ss, int se, int qi, int mark)
{
	A+=a[cur]*mark;
	B+=b[cur]*mark;
	if(ss==se) return;
	int mid=(ss+se)>>1;
	if(qi<=mid) Get(l[cur],ss,mid,qi,mark);
	else Get(r[cur],mid+1,se,qi,mark);
}
int main()
{
	int n,i,l,r,u,aa,bb,v,x,q;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i %i %i %i %i",&l,&r,&u,&aa,&bb,&v);
		Set(root[i-1],root[i],0,N,0,l,0,u);
		Set(root[i],root[i],0,N,l+1,r,aa,bb);
		Set(root[i],root[i],0,N,r+1,N,0,v);
	}
	scanf("%i",&q);
	long long last=0;
	while(q--)
	{
		scanf("%i %i %i",&l,&r,&x);
		x=(x+last)%1000000000;
		int t=x;
		if(t>N) t=N;
		A=0;
		B=0;
		Get(root[l-1],0,N,t,-1);
		Get(root[r],0,N,t,1);
		last=A*x+B;
		printf("%lld\n",last);
	}
	return 0;
}