#include <stdio.h>
#include <cstring>
bool used[10000];
char str[1050];
int main()
{
	int n,k,i;
	scanf("%s",&str);
	n=(unsigned) strlen(str);
	scanf("%i",&k);
	if(k>n)
	{
		printf("impossible\n");
		return 0;
	}
	int sol=0;
	for(i=0;i<n;i++)
	{
		if(!used[str[i]]) sol++;
		used[str[i]]=true;
	}
	if(sol>k) printf("0\n");
	else printf("%i\n",k-sol);
	return 0;
}