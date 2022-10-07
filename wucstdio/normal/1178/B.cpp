#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
char s[1000005];
int n;
ll sum1[1000005],sum2[1000005];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		sum1[i]=sum1[i-1];
		if(s[i]=='v'&&s[i-1]=='v')sum1[i]++;
	}
	for(int i=n;i>=1;i--)
	{
		sum2[i]=sum2[i+1];
		if(s[i]=='v'&&s[i+1]=='v')sum2[i]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='o')ans+=sum1[i-1]*sum2[i+1];
	printf("%I64d\n",ans);
	return 0;
}