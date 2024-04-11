#include <stdio.h>
#include <cstring>
char word[2][200];
int main()
{
	int n,i;
	scanf("%s",&word[0]);
	scanf("%s",&word[1]);
	n=(unsigned) strlen(word[0]);
	for(i=0;i<n;i++)
	{
		if(word[0][i]<'a') word[0][i]+='a'-'A';
		if(word[1][i]<'a') word[1][i]+='a'-'A';
		if(word[0][i]>word[1][i])
		{
			printf("1\n");
			return 0;
		}
		if(word[0][i]<word[1][i])
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("0\n");
	return 0;
}