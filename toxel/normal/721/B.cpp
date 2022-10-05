#include<bits/stdc++.h>
int main()
{
	char s[101][101],c[101];
	int n,k,i,j,less=0,more=0,len;
	scanf("%d%d",&n,&k);
	for (i = 0;i < n;i++)
	{
		getchar();
		scanf("%s",s[i]);
	}
	getchar();
	scanf("%s",c);
	len = strlen(c);
	for (i = 0;i < n;i++)
	{
		if (strlen(s[i]) < len)
			less++;
		else if (strlen(s[i]) == len)
			more++;
	}
	more = more + less;
	printf("%d %d\n",less + 1 + (less) / k * 5,more + (more - 1) / k * 5);
	return 0;
}