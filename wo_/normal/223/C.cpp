#include<cstdio>

using namespace std;

const long long mod=1000000007;

long long coe[2200];

int in[2200];

long long pown(int a,int n)
{
	if(n==0) return 1;
	long long aa=pown(a,n/2);
	long long res=aa*aa;
	res%=mod;
	if(n%2==1) res*=a;
	res%=mod;
	return res;
}

long long inv(int a)
{
	return pown(a,(int)mod-2);
}

long long ans[2200]={};

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	K--;
	coe[1]=1;
	coe[2]=K+1;
	long long num=K+1,den=1;
	for(int i=3;i<=N;i++)
	{
		num*=(K+i-1);
		num%=mod;
		den*=(i-1);
		den%=mod;
		coe[i]=num*(inv(den));
		coe[i]%=mod;
	}
	for(int i=1;i<=N;i++)
	{
		scanf("%d",in+i);
	}
	if(K==-1)
	{
		for(int i=1;i<=N;i++)
		{
			printf("%d%c",in[i],i==N?'\n':' ');
		}
		return 0;
	}
	for(int i=1;i<=N;i++)
	{
		long long tmp=0;
		for(int j=1;j<=i;j++)
		{
			tmp+=((long long)in[j]*coe[i+1-j]);
			tmp%=mod;
		}
		ans[i]=tmp;
		ans[i]+=mod;
		ans[i]%=mod;
	}
	for(int i=1;i<=N;i++)
	{
		printf("%d%c",(int)ans[i],i==N?'\n':' ');
	}
	return 0;
}