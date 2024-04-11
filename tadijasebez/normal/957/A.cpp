#include <stdio.h>
char s[100000];
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	bool ok=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]!='?')
		{
			if(s[i-1]==s[i] || s[i+1]==s[i]) return printf("No\n"),0;
		}
		else
		{
			if(s[i+1]=='?' || s[i-1]=='?' || s[i+1]==s[i-1] || i==1 || i==n) ok=1;
		}
	}
	if(ok) printf("Yes\n");
	else printf("No\n");
	return 0;
}