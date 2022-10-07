#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,a[100005],prime[100005],num,id[200005],m1[200005],m2[200005],c[200005];
bool flag[200005];
void pre(int n)
{
	flag[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!flag[i])
		{
			prime[++num]=i;
			id[i]=num;
		}
		for(int j=1;j<=num&&prime[j]*i<=n;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int main()
{
	memset(m1,0x3f,sizeof(m1));
	memset(m2,0x3f,sizeof(m2));
	pre(200000);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=1;1ll*prime[j]*prime[j]<=a[i];j++)
		{
			int cnt=0;
			while(a[i]%prime[j]==0)
			{
				cnt++;
				a[i]/=prime[j];
			}
			if(cnt==0)continue;
			c[j]++;
			if(cnt<m1[j])
			{
				m2[j]=m1[j];
				m1[j]=cnt;
			}
			else if(cnt<m2[j])m2[j]=cnt;
		}
		if(a[i]!=1)
		{
			int j=id[a[i]];
			c[j]++;
			m2[j]=m1[j],m1[j]=1;
		}
	}
	ll ans=1;
	for(int i=1;i<=num;i++)
	{
		if(c[i]<=n-2)continue;
		if(c[i]==n-1)
		{
			while(m1[i]--)
			  ans*=prime[i];
		}
		if(c[i]==n)
		{
			while(m2[i]--)
			  ans*=prime[i];
		}
	}
	printf("%lld\n",ans);
	return 0;
}