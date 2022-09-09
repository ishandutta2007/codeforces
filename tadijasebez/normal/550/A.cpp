#include <stdio.h>
#include <cstring>
const int N=100050;
bool dp[N];
char word[N];
int main()
{
	int n,i;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=1;i<n-1;i++)
	{
		if(dp[i-1] || (word[i-1]=='A' && word[i]=='B')) dp[i]=true;
		if(dp[i-1] && word[i]=='B' && word[i+1]=='A')
		{
			printf("YES\n");
			return 0;
		}
	}
	for(i=1;i<n-1;i++) dp[i]=false;
	for(i=1;i<n-1;i++)
	{
		if(dp[i-1] || (word[i-1]=='B' && word[i]=='A')) dp[i]=true;
		if(dp[i-1] && word[i]=='A' && word[i+1]=='B')
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}