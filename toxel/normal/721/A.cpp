#include<bits/stdc++.h>
int main()
{
	int i,j=0,n,ans[101];
	char s[101];
	scanf("%d%s",&n,s);
	for (i=0;i<strlen(s);)
	{
		if (s[i]=='W')
		{
			i++;
			continue;
		}
		ans[j]=0;
		while(s[i]=='B'&&i<strlen(s))
		{
			ans[j]++;
			i++;
		}
		j++;
	}
	if (j == 0)
	{
		printf("0");
		return 0;
	}
	printf("%d\n",j);
	for (i=0;i<j;i++)
		printf("%d ",ans[i]);
	return 0;
}