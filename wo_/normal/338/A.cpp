#include<cstdio>

using namespace std;

const long long mod=1000000009;

long long ex(int e)
{
	if(e==0) return 1;
	if(e==1) return 2;
	long long tmp=ex(e/2);
	tmp*=tmp;
	if(e%2==1) tmp*=2;
	return tmp%mod;
}

long long get(int n,int K)
{
	int a=n/K;
	long long res=(ex(a+1)-2)*K;
	res%=mod;
	int r=n%K;
	res+=r;
	res%=mod;
	return res;
}

int main()
{
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	int a=N/K,b=N%K;
	int m=a*(K-1)+b;
	if(m>=M)
	{
		printf("%d\n",M);
		return 0;
	}
	int c=N-M;
	int d=N-K*c;
	long long e=get(d,K);
	e+=(K-1)*c;
	e%=mod;
	e+=mod;
	e%=mod;
	printf("%d\n",(int)e);
	return 0;
}