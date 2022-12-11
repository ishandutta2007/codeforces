#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[200005];
int main()
{
	scanf("%s",str);
	if (strlen(str)&1)
	{
		printf("-1");
		return 0;
	}
	int cnt[256]={};
	for (int i = 0; str[i]; i++)
	{
		cnt[str[i]]++;
	}
	int u=cnt['U'],d=cnt['D'],l=cnt['L'],r=cnt['R'];
	int ans=abs((u-d)/2)+abs((l-r)/2);
	printf("%d", ans+((u+d)&1));
}