#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#define N 50001
int main()
{
	char s[N];
	int a[26],i,j,k;
	bool flag;
	scanf("%s",s);
	if (strlen(s)<26)
	{
		printf("-1");
		return  0;
	}
	for (i=0;i<=strlen(s)-26;i++)
	{
		k=0;
		flag=true;
		memset(a,0,sizeof(a));
		for (j=0;j<26;j++)
			if (s[i+j]!='?')
				a[s[i+j]-'A']++;
		for (j=0;j<26;j++)
			if (a[j]>1)
			{
				flag=false;
				break;
			}
		if (flag)
			break;
	}
	if (flag)
	{
		for (j=0;j<i;j++)
			if (s[j]=='?')
				printf("A");
			else
				printf("%c",s[j]);
		for (j=0;j<26;j++)
		{
			while (a[k])
				k++;
			if (s[i+j]!='?')
				printf("%c",s[i+j]);
			else
			{
				printf("%c",k+'A');
				k++;
			}
		}
		for (j=i+26;j<strlen(s);j++)
			if (s[j]=='?')
				printf("A");
			else
				printf("%c",s[j]);
		return 0;
	}
	printf("-1\n");
	return 0;
}