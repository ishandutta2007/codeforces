#include<cstdio>
#include<iostream>

using namespace std;

long long todown[10100100],here[10100100];

int divPrime[10100100];

long long e[10100100];

long long M=0;

long long get(long long n,int p)
{
	long long res=0;
	while(n>0)
	{
		n/=p;
		res+=n;
	}
	return res;
}

long long binary_search(int p)
{
	long long lb=0,ub=M;
	while(ub-lb>1)
	{
		long long mid=(ub+lb)/2;
		long long f=get(mid,p);
		if(f>=e[p]) ub=mid;
		else lb=mid;
	}
	return ub;
}

int main()
{
	for(int i=0;i<=10100100;i++) divPrime[i]=-1;
	divPrime[1]=1;
	for(int i=2;i<=10100100;i++)
	{
		if(divPrime[i]!=-1) continue;
		divPrime[i]=i;
		for(int j=2;i*j<=10100100;j++)
		{
			divPrime[i*j]=i;
		}
	}
	int K;
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		int a;
		scanf("%d",&a);
		M+=a;
		todown[a]++;
	}
	for(int i=10010010;i>=2;i--)
	{
		int p=divPrime[i];
		todown[i-1]+=todown[i];
		e[p]+=todown[i];
		int n=i/p;
		if(n!=1)
		{
			here[n]+=todown[i];
			here[n]+=here[i];
		}
		e[p]+=here[i];
	}
	long long ans=1;
	for(int i=2;i<10001001;i++)
	{
		if(divPrime[i]!=i) continue;
		ans=max(ans,binary_search(i));
	}
	cout<<ans<<"\n";
	return 0;
}