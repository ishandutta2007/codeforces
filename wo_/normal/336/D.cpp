#include<cstdio>

using namespace std;

const long long mod=1000000007;

long long ex(int a,int e)
{
	if(e==0) return 1;
	long long tmp=ex(a,e/2);
	tmp*=tmp;
	tmp%=mod;
	if(e%2==1) tmp*=a;
	tmp%=mod;
	return tmp;
}

long long inv(int a)
{
	return ex(a,mod-2);
}

int main()
{
	int ones,zeros,fin;
	scanf("%d%d%d",&zeros,&ones,&fin);
	int total=zeros+ones;
	if(total==1)
	{
		int ans;
		if(fin==1&&ones==1) ans=1;
		else if(fin==0&&zeros==1) ans=1;
		else ans=0;
		printf("%d\n",ans);
		return 0;
	}
	if(ones==0)
	{
		int a=(zeros%2)^1;
		if(a==fin) printf("1\n");
		else printf("0\n");
		return 0;
	}
	if(total==2)
	{
		if(ones==0&&fin==1) printf("1\n");
		else if(ones==1&&fin==0) printf("2\n");
		else if(ones==2&&fin==0) printf("1\n");
		else printf("0\n");
		return 0;
	}
	if(ones==1)
	{
		int ans=0;
		for(int i=0;i<zeros;i++)
		{
			int a=(i%2);
			if(a==fin) ans++;
		}
		if(((zeros%2)^1)==fin) ans++;
		printf("%d\n",ans);
		return 0;
	}
	long long coe=1;
	int N=zeros,M=ones;
	for(int i=N+M-1;i>=N+1;i--)
	{
		coe*=i;
		coe%=mod;
	}
	for(int i=1;i<=M-1;i++)
	{
		coe*=inv(i);
		coe%=mod;
	}
	int x=N+M-1,y=N;
	long long ans=0;
	for(int i=0;i<=zeros;i++)
	{
		//i times 0 then 1
		if(i%2==fin)
		{
			ans+=coe;
			ans%=mod;
		}
		coe*=y;
		coe%=mod;
		coe*=inv(x);
		coe%=mod;
		x--;y--;
	}
	ans%=mod;
	ans+=mod;
	ans%=mod;
	printf("%d\n",ans);
	return 0;
}