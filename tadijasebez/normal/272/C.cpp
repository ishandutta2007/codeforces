#include <stdio.h>
#define ll long long
const int N=100050;
const int M=2*N;
ll x[M],Lazy[M];
int ls[M],rs[M],clock,root,a[N];
ll max(ll a, ll b){ return a>b?a:b;}
void Build(int &c, int ss, int se)
{
	c=++clock;
	if(ss==se){x[c]=a[ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=max(x[ls[c]],x[rs[c]]);
}
void Set(int c, int ss, int se, int qs, int qe, ll val)
{
	if(Lazy[c]>0)
	{
		x[c]=max(x[c],Lazy[c]);
		if(ss!=se)
		{
			Lazy[ls[c]]=max(Lazy[ls[c]],Lazy[c]);
			Lazy[rs[c]]=max(Lazy[rs[c]],Lazy[c]);
		}
		Lazy[c]=0;
	}
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		x[c]=max(x[c],val);
		if(ss!=se)
		{
			Lazy[ls[c]]=max(Lazy[ls[c]],val);
			Lazy[rs[c]]=max(Lazy[rs[c]],val);
		}
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
	x[c]=max(x[ls[c]],x[rs[c]]);
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(Lazy[c]>0)
	{
		x[c]=max(x[c],Lazy[c]);
		if(ss!=se)
		{
			Lazy[ls[c]]=max(Lazy[ls[c]],Lazy[c]);
			Lazy[rs[c]]=max(Lazy[rs[c]],Lazy[c]);
		}
		Lazy[c]=0;
	}
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int main()
{
	int n,q,i,w,h;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	Build(root,1,n);
	scanf("%i",&q);
	while(q--){
		scanf("%i %i",&w,&h);
		ll tmp=Get(root,1,n,1,w);
		printf("%lld\n",tmp);
		Set(root,1,N,1,w,tmp+h);
	}
	return 0;
}