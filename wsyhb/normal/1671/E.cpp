#include<bits/stdc++.h>
using namespace std;
const int max_len=1<<18|5;
char s[max_len];
string S[max_len];
int dp[max_len];
const int mod=998244353;
int main()
{
	int n;
	scanf("%d%s",&n,s+1);
	int len=(1<<n)-1;
	for(int i=len;i>=1;--i)
	{
		S[i]=s[i],dp[i]=0;
		if((i<<1)<=len)
		{
			S[i]+=min(S[i<<1],S[i<<1|1])+max(S[i<<1],S[i<<1|1]);
			dp[i]=dp[i<<1]+dp[i<<1|1];
			if(S[i<<1]!=S[i<<1|1])
				++dp[i];
		}
	}
	int ans=1;
	for(int i=1;i<=dp[1];++i)
	{
		ans<<=1;
		ans-=ans>=mod?mod:0;
	}
	printf("%d\n",ans);
	return 0;
}