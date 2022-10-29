#include <bits/stdc++.h>
using namespace std;

int n,K,x,N,nn;
long long a[100001],b[100001];
int sum[100001];
long long Ans;

void FWT(long long a[],int l,int r,int tp)
{
	if (l==r-1) return;
	int mid=(l+r)>>1;
	FWT(a,l,mid,tp); FWT(a,mid,r,tp);
	for (int i=0;i<mid-l;i++)
	{
		long long tmp0,tmp1;
		//xor:
		if (tp==0) tmp0=a[l+i]+a[mid+i],tmp1=a[l+i]-a[mid+i];
		else tmp0=(a[l+i]+a[mid+i])/2,tmp1=(a[l+i]-a[mid+i])/2;
		a[l+i]=tmp0; a[mid+i]=tmp1;
	}
}

int main()
{
	for (int i=1;i<=100000;i++) sum[i]=sum[i>>1]+(i&1);
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		nn=max(nn,x+1);
		a[x]++; b[x]++;
	}
	for (N=1;N<nn;N<<=1);
	FWT(a,0,N,0); FWT(b,0,N,0);
	for (int i=0;i<N;i++) a[i]*=b[i];
	FWT(a,0,N,1);
	
	for (int i=0;i<N;i++)
		if (sum[i]==K) Ans+=a[i];
	if (K==0) Ans-=n;
	printf("%I64d\n",Ans/2);
}