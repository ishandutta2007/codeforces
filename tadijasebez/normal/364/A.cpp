#include <stdio.h>
#include <cstring>
#define ll long long
const int N=4050;
const int M=N*10;
int cnt[M],dp[N];
char word[N];
ll sol;
int main()
{
	int a,i,j,n;
	scanf("%i",&a);
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=0;i<n;i++) dp[i+1]=dp[i]+word[i]-'0';
	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
		{
			cnt[dp[i]-dp[j]]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
		{
			int tmp=dp[i]-dp[j];
			if(tmp!=0 && a%tmp==0)
			{
				int b=a/tmp;
				if(b<M) sol+=cnt[b];
			}
			if(a==0 && tmp==0)
			{
				sol+=n*(n+1)/2;
			}
		}
	}
	printf("%lld\n",sol);
	return 0;
}