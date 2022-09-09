#include <stdio.h>
#include <cstring>
char word[1000];
int dp[1000]; 
int main()
{
	int n,i;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+(word[i-1]=='1');
		if(i>=7 && (dp[i]-dp[i-7]==7 || dp[i]-dp[i-7]==0))
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}