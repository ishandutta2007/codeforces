#include<cstdio>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

int N,M,K;

int Ma=-1,mi=1<<29;

long long exp[1100100];

int main()
{
	scanf("%d%d%d",&N,&M,&K);
	bool ok=true;
	int cnt=0;
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(b-a!=1&&b-a!=K+1)
		{
			ok=false;
		}
		if(b-a==K+1)
		{
			Ma=max(Ma,a);
			mi=min(mi,a);
			cnt++;
		}
	}
	if(ok==false)
	{
		printf("0\n");
		return 0;
	}
	if(Ma!=-1&&Ma-mi>=K+1)
	{
		printf("0\n");
		return 0;
	}
	exp[0]=1;
	for(int i=1;i<=1000000;i++)
	{
		exp[i]=exp[i-1]*2;
		exp[i]%=mod;
	}
//	printf("a\n");
	long long ans=0;
	if(Ma==-1)
	{
//		printf("b\n");
		for(int i=1;i<=N-K-1;i++)
		{
			int ub=min(N-K-1,i+K);
			int num=ub-i;
			ans+=exp[num];
			ans%=mod;
		}
		ans++;
	}
	else
	{
		for(int i=1;i<=mi;i++)
		{
			if(i+K<Ma) continue;
			int ub=min(i+K,N-K-1);
			int num=(ub-(i-1))-cnt;
			if(i<mi) num--;
			if(num<0) continue;
			ans+=exp[num];
			ans%=mod;
//			printf("%d %d\n",i,num);
		}
	}
	ans+=mod;
	ans%=mod;
	printf("%d\n",(int)ans);
	return 0;
}