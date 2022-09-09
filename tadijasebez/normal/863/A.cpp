#include <stdio.h>
#include <cstring>
char word[100];
int main()
{
	int n,i;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	while(n>0 && word[n-1]=='0') n--;
	for(i=0;i<n;i++)
	{
		if(word[i]!=word[n-i-1]) 
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}