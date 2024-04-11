#include <stdio.h>
#include <cstring>
char s[20];
int main()
{
	int n,i;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]!='1' && s[i]!='4') return printf("NO\n"),0;
		if(s[i]=='1')
		{
			if(s[i+1]=='4' && s[i+2]=='4' && s[i+3]=='4') return printf("NO\n"),0;
		}
		if(i==1 && s[i]=='4') return printf("NO\n"),0;
	}
	printf("YES\n");
	return 0;
}