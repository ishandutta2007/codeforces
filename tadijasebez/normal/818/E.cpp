#include <stdio.h>
#define ll long long
const int N=100050;
const int M=2*N;
int x[M],ls[M],rs[M],cnt,root,a[N],mod;
void Build(int &c, int ss, int se)
{
	c=++cnt;
	if(ss==se){ x[c]=a[ss]%mod;return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=(ll)x[ls[c]]*x[rs[c]]%mod;
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 1;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return (ll)Get(ls[c],ss,mid,qs,qe)*Get(rs[c],mid+1,se,qs,qe)%mod;
}
ll sol;
int main()
{
	int n,i;
	scanf("%i %i",&n,&mod);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	Build(root,1,n);
	for(i=1;i<=n;i++)
	{
		int top=i,bot=1,mid,ans=0;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(Get(root,1,n,mid,i)==0) ans=mid,bot=mid+1;
			else top=mid-1;
		}
		sol+=ans;
	}
	printf("%lld\n",sol);
	return 0;
}