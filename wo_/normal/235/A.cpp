#include<cstdio>
#include<iostream>

using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	int N;
	scanf("%d",&N);
	if(N==1)
	{
		printf("1\n");
		return 0;
	}
	if(N==2)
	{
		printf("2\n");
		return 0;
	}
	if(N%2==1)
	{
		long long ans=(long long)N*(long long)(N-1)*(long long)(N-2);
		cout<<ans<<"\n";
	}
	else
	{
	//	long long ans=(long long)N*(long long)(N-1)*(long long)(N-3);
		long long tmp=(long long)N*(long long)(N-1);
		long long M=0;
		for(long long i=1;i<=N-2;i++)
		{
			long long d=gcd(tmp,i);
			M=max(M,tmp*i/d);
		}
		M=max(M,(long long)(N-3)*(long long)(N-1)*(long long)(N-2));
		cout<<M<<"\n";
	}
	return 0;
}