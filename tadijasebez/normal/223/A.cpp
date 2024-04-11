#include <stdio.h>
#include <cstring>
const int N=100050;
char s[N];
int S[N],c,dp[N],ans,l,r=-1;
int main()
{
	scanf("%s",s+1);
	s[0]='#';
	int n=strlen(s)-1,i;
	for(i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+(s[i]=='[');
		if(s[i]=='[' || s[i]=='(') S[c++]=i;
		else if(s[i]==']' && s[S[c-1]]!='[' || s[i]==')' && s[S[c-1]]!='(') c=1,S[0]=i;
		else
		{
			c--;
			if(ans<dp[i]-dp[S[c-1]]) ans=dp[i]-dp[S[c-1]],l=S[c-1]+1,r=i;
		}
	}
	printf("%i\n",ans);
	for(i=l;i<=r;i++) printf("%c",s[i]);
	printf("\n");
	return 0;
}