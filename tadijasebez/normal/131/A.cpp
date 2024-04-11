#include <stdio.h>
#include <cstring>
char word[105];
int main()
{
	int n,i;
	bool ok=true;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=1;i<n;i++) if(word[i]>='a') ok=false;
	if(ok)
	{
		for(i=0;i<n;i++)
		{
			if(word[i]>='a') word[i]-='a'-'A';
			else word[i]+='a'-'A';
		}
	}
	printf("%s",word);
	return 0;
}