#include<bits/stdc++.h>
int main()
{
	char s[101][101];
	int n,i,j,p[101],count;
	bool flag = true;
	scanf("%d",&n);
	for (i = 0;i < n;i++)
		scanf("%d",&p[i]);
	getchar();
	for (i = 0;i < n;i++)
		gets(s[i]);
	for (i = 0;i < n;i++)
	{
		count = 0;
		for (j = 0;j < strlen(s[i]);j++)
			if (s[i][j] == 'a' || s[i][j] == 'e' || s[i][j] == 'i' || s[i][j] == 'u' || s[i][j] == 'o' || s[i][j] == 'y')
				count++;
		if (count != p[i])
			flag = false;
	}
	if (flag)
		printf("YES");
	else
		printf("NO");
	return 0;
}