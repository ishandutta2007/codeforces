#include <stdio.h>
#include <cstring>
int up,low;
char word[105];
int main()
{
	int n,i;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=0;i<n;i++) if(word[i]>='a') low++;
	up=n-low;
	//printf("%i %i a:%i A:%i\n",low,up,'a','A');
	if(up>low)
	{
		for(i=0;i<n;i++)
		{
			if(word[i]>='a')
			{
				word[i]-='a'-'A';
			}
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(word[i]<='Z')
			{
				word[i]+='a'-'A';
			}
		}
	}
	printf("%s",word);
	return 0;
}