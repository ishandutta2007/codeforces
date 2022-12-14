#include<cstdio>

using namespace std;

const long long mod=1000000009;

long long fac[8080];

long long ex(int a,int n)
{
	if(n==0) return 1;
	long long res=ex(a,n/2);
	res*=res;
	res%=mod;
	if(n%2==1) res*=a;
	res%=mod;
	return res;
}

long long inv(int a)
{
	return ex(a,mod-2);
}

long long C(int n,int k)
{
	long long res=fac[n];
	res*=inv(fac[k]);
	res%=mod;
	res*=inv(fac[n-k]);
	return res%mod;
}

int main()
{
	fac[0]=1;
	for(int i=1;i<8080;i++)
	{
		fac[i]=fac[i-1]*i;
		fac[i]%=mod;
	}
	int N,W,B;
	scanf("%d%d%d",&N,&W,&B);
	long long ans=0;
	long long coe=(fac[W]*fac[B])%mod;
	for(int x=1;x<=N-2;x++)
	{
		if(x>B||N-x>W) continue;
		long long tmp=C(B-1,x-1)*C(W-1,N-x-1);
		tmp%=mod;
		tmp*=(N-x-1);
		tmp%=mod;
		ans+=coe*tmp;
		ans%=mod;
	}
	ans+=mod;
	ans%=mod;
	printf("%d\n",(int)ans);
	return 0;
}