#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int prime[1000005],num;
bool flag[1000005];
ll n,sum[100005];
char s[100005];
inline int read()
{
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	return c-'0';
}
void pre()
{
	flag[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(!flag[i])prime[++num]=i;
		for(int j=1;j<=num&&prime[j]*i<=1000000;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int main()
{
	pre();
	scanf("%d",&n);
		bool flag=0;
		scanf("%s",s+1);
		if(n==1)
		{
			printf("NO\n");
			return 0;
		}
		for(int i=1;i<=n;i++)
		  sum[i]=sum[i-1]+s[i]-'0';
		while(sum[n]==sum[n-1]&&n>=1)n--;
		if(n==0)
		{
			printf("YES\n");
			return 0;
		}
		for(int i=1;i<=num;i++)
		{
			int p=prime[i];
			if(sum[n]%p!=0)continue;
			if(p>sum[n])break;
			int last=0;
			ll x=sum[n]/p;
			for(int i=1;i<=n;i++)
			{
				if(sum[i]-sum[last]==x)last=i;
				else if(sum[i]-sum[last]>x)break;
			}
			if(last==n)
			{
				flag=1;
				break;
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	return 0;
}