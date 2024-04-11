#include <stdio.h>
const int N=100050;
const int M=N*50;
int x[M],ls[M],rs[M],clock,root[N];
void Set(int p, int &c, int ss, int se, int qi, int val)
{
	c=++clock,x[c]=x[p]+val,ls[c]=ls[p],rs[c]=rs[p];
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi,val);
	else Set(rs[p],rs[c],mid+1,se,qi,val);
}
int ans;
int max(int a, int b){ return a>b?a:b;}
void Get(int c, int ss, int se, int k)
{
	//printf("%i %i %i %i\n",ss,se,x[c],k);
	int mid=ss+se>>1;
	if(ss==se)
	{
		if(x[c]<=k) ans=max(ans,ss);
		return;
	}
	if(x[ls[c]]>k)
	{
		Get(ls[c],ss,mid,k);
	}
	else
	{
		Get(rs[c],mid+1,se,k-x[ls[c]]);
		if(ans<mid) Get(ls[c],ss,mid,k);
	}
}
int a[N],index[N];
int main()
{
	int n,i,k;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=n;i>0;i--)
	{
		Set(root[i+1],root[i],1,n,i,1);
		if(index[a[i]]) Set(root[i],root[i],1,n,index[a[i]],-1);
		index[a[i]]=i;
	}
	int t;
	for(k=1;k<=n;k++)
	{
		i=1,t=0;
		while(i<=n)
		{
			//printf("%i ",i);
			t++;
			ans=0;
			Get(root[i],1,n,k);
			i=ans+1;
		}
		printf("%i ",t);
	}
	printf("\n");
	return 0;
}