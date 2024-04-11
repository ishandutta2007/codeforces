#include <stdio.h>
const int N=200050;
const int M=2*N;
#define ll long long
const ll inf=1000000000ll*100000000ll;
ll x[M],Lazy[M],A[N+1];
int ls[M],rs[M],clock,root;
ll min(ll a, ll b){ return a>b?b:a;}
ll Calc(int c){ return x[c]+Lazy[c];}
void Build(int &c, int ss, int se)
{
	c=++clock;
	if(ss==se)
	{
		x[c]=A[ss];
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=min(Calc(ls[c]),Calc(rs[c]));
}
void Set(int c, int ss, int se, int qs, int qe, int val)
{
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		Lazy[c]+=val;
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
	x[c]=min(Calc(ls[c]),Calc(rs[c]));
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return inf;
	if(qs<=ss && qe>=se) return Calc(c);
	int mid=ss+se>>1;
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe))+Lazy[c];
}
int main()
{
	int n,i,q,l,r,k;
	char t;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%I64d",&A[i]);
	Build(root,1,N);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&l,&r);
		l++;r++;
		scanf("%c",&t);
		if(t=='\n')
		{
			ll sol;
			if(l<=r) sol=Get(root,1,N,l,r);//printf("%lld\n",Get(root,1,N,l,r));
			else sol=min(Get(root,1,N,1,r),Get(root,1,N,l,n));//printf("%lld\n",min(Get(root,1,N,1,r),Get(root,1,N,l,n)));
			printf("%I64d\n",sol);
		}
		else
		{
			scanf("%i",&k);
			if(l<=r) Set(root,1,N,l,r,k);
			else Set(root,1,N,1,r,k),Set(root,1,N,l,n,k);
		}
	}
	return 0;
}