#include <stdio.h>
#include <cstring>
#define ll long long
const int N=1000500;
char ch[N];
int dp[N];
ll sol;
int main()
{
	int k,n,i;
	scanf("%i",&k);
	scanf("%s",&ch);
	n=strlen(ch);
	for(i=0;i<n;i++) dp[i+1]=dp[i]+(ch[i]=='1');
	int top,bot,mid,L,R;
	for(i=0;i<n;i++)
	{
		L=R=i;
		top=n;bot=i+1;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(dp[mid]-dp[i]<k) L=mid,bot=mid+1;
			else top=mid-1;
		}
		top=n;bot=i+1;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(dp[mid]-dp[i]<=k) R=mid,bot=mid+1;
			else top=mid-1;
		}
		sol+=R-L;
	}
	printf("%lld\n",sol);
	return 0;
}