#include<bits/stdc++.h>
using namespace std;
const int N=100005,mod=1e9+7;
inline void add(int &a,int b){a+=b;if(a>=mod)a-=mod;}
int dp[N];
char s[N];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='m'||s[i]=='w')
		{
			puts("0");
			return 0;
		}
		add(dp[i],dp[i-1]);
		if(s[i]==s[i-1]&&(s[i]=='u'||s[i]=='n'))
			add(dp[i],dp[i-2]);
	}
	printf("%d\n",dp[n]);
	return 0;
}