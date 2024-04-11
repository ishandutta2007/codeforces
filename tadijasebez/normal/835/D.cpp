#include <stdio.h>
#include <cstring>
int dp[5005][5005];
bool mark[5005][5005];
int sol[5005];
char s[5005];
int main()
{
	int n,i,j,l,r;
	scanf("%s",&s);
	n=(unsigned) strlen(s);
	for(i=1;i<=n;i++)
	{
		for(j=0;j+i<=n;j++)
		{
			l=j;
			r=j+i-1;
			if((i==1 || i==2 || mark[l+1][r-1]) && s[l]==s[r]) mark[l][r]=true;
			if(mark[l][r])
			{
				int k=(l+r-1)>>1;
				if(k<0) k=0;
				dp[l][r]=dp[l][k]+1;
				sol[dp[l][r]]++;
			}
		}
	}
	for(i=n-1;i>0;i--) sol[i]+=sol[i+1];
	for(i=1;i<=n;i++)
	{
		printf("%i ",sol[i]);
	}
	return 0;
}