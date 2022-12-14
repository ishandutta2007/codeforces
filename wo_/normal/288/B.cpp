#include<cstdio>
#include<iostream>

using namespace std;

const long long mod=1000000007;

long long ex(int a,int e)
{
	long long res=1;
	for(int i=0;i<e;i++)
	{
		res*=a;
		res%=mod;
	}
	return res;
}

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	long long ans;
	if(N==K)
	{
		ans=ex(N,N-1);
	}
	else
	{
		ans=ex(K,K-1);
		ans*=ex(N-K,N-K);
		ans%=mod;
	}
	ans%=mod;
	ans+=mod;
	ans%=mod;
	cout<<ans<<"\n";
	return 0;
}