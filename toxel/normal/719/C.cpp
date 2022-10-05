#include<bits/stdc++.h>
const int N=200000;
int main()
{
	int n,t,i,j;
	char grade[N];
	scanf("%d%d%s",&n,&t,grade);
	for (i=0;i<n;i++)
		if (grade[i]=='.')
			break;
	for (j=i+1;j<n;j++)
		if (grade[j]>='5')
			break;
	if (j==n)
	{
		printf("%s",grade);
		return 0;
	}
	n=j;
	do
	{
		if (grade[j-1]=='.')
		{
			j--;
			n--;
		}
		while (grade[j-1]=='9')
		{
			if (grade[j-1]=='.')
			{
				j--;
				n--;
			}
			grade[j-1]='0';
			if (j==1)
			{
				printf("1");
				for (j=0;j<n;j++)
					printf("%c",grade[j]);
				return 0;
			}
			j--;
		}
		grade[j-1]=grade[j-1]+1;
		t--;
		n--;
	}
	while (grade[--j]=='5'&&t&&j>i);
	for (j=0;j<=n;j++)
		printf("%c",grade[j]);
}