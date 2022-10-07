#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int prime[3000005],sum[3000005],minn[15000005],num;
bool flag[15000005];
int n,a[300005],d;
void pre()
{
	for(int i=2;i<=15000000;i++)
	{
		if(!flag[i])prime[++num]=i,minn[i]=num;
		for(int j=1;j<=num&&prime[j]*i<=15000000;j++)
		{
			flag[i*prime[j]]=1;
			minn[i*prime[j]]=j;
			if(i%prime[j]==0)break;
		}
	}
}
int gcd(int a,int b)
{
	if(a==0)return b;
	return gcd(b%a,a);
}
int main()
{
//	printf("%d\n",(sizeof(prime)+sizeof(minn)+sizeof(sum)+sizeof(flag))/1024/1024);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d=gcd(d,a[i]);
	}
	pre();
	for(int i=1;i<=n;i++)
	  a[i]/=d;
	for(int i=1;i<=n;i++)
	{
		while(a[i]!=1)
		{
			sum[minn[a[i]]]++;
			int x=prime[minn[a[i]]];
			while(a[i]%x==0)a[i]/=x;
		}
	}
	int maxx=0;
	for(int i=1;i<=num;i++)
	  maxx=max(maxx,sum[i]);
	if(maxx==0)printf("-1\n");
	else printf("%d\n",n-maxx);
	return 0;
}