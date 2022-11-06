#include<stdio.h>
char ans[100011];
int main()
{
	int i;
	scanf("%s", ans);
	for(i=0; ans[i] && ans[i] == '1'; i++);
	if(ans[i])
	{
		for(i=0; ans[i] == '1'; i++)printf("1");
		for(i++; ans[i]; i++)printf("%c", ans[i]);
	}
	else
	{
		for(i=0; ans[i+1]; i++)printf("1");
	}
	return 0;
}