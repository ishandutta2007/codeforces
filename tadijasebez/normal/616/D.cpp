#include <stdio.h>
const int N=500050;
const int M=40*N;
int x[M],ls[M],rs[M],clock,root[N];
void Set(int p, int &c, int ss, int se, int qi, int val)
{
	c=++clock;ls[c]=ls[p];rs[c]=rs[p];x[c]=x[p]+val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi,val);
	else Set(rs[p],rs[c],mid+1,se,qi,val);
}
int A;
int max(int a, int b){ return a>b?a:b;}
void Get(int c, int ss, int se, int k)
{
	if(ss==se)
	{
		if(x[c]<=k) A=max(A,ss);
		return;
	}
	int mid=ss+se>>1;
	if(x[ls[c]]>k)
	{
		Get(ls[c],ss,mid,k);
		return;
	}
	A=max(A,mid);
	Get(rs[c],mid+1,se,k-x[ls[c]]);
}
int a[N],p[N*2],l,r;
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=n;i;i--)
	{
		Set(root[i+1],root[i],1,n,i,1);
		if(p[a[i]]) Set(root[i],root[i],1,n,p[a[i]],-1);
		p[a[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		A=0;
		Get(root[i],1,n,k);
		if(A-i>=r-l) r=A,l=i;
	}
	printf("%i %i\n",l,r);
	return 0;
}