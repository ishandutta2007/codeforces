#include<stdio.h>
char in[1000];
int s[1000][2];
int main()
{
	int n, i, j;
	scanf("%d%s", &n, in+1);
	for(i=1; i<=n; i++)
	{
		s[i][0] = s[i-1][0]; s[i][1] = s[i-1][1];
		if(in[i]=='U') s[i][0]++;
		if(in[i]=='D') s[i][0]--;
		if(in[i]=='L') s[i][1]++;
		if(in[i]=='R') s[i][1]--;
	}
	int c = 0;
	for(i=0; i<n; i++)for(j=i+1; j<=n; j++)
	{
		if(s[i][0] == s[j][0] && s[i][1] == s[j][1])c++;
	}
	printf("%d", c);
	return 0;
}