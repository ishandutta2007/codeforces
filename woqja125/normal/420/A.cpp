#include<stdio.h>
#include<string.h>
char mirror[]="A000000HI000M0O0000TUVWXY0";
char s[100001];
int main()
{
	int n, i;
	scanf("%s", s);
	n = strlen(s);
	for(i=0; i<=n/2; i++)
	{
		if(s[i] != s[n-i-1] || s[i] != mirror[s[i] - 'A'])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}