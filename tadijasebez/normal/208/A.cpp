#include <stdio.h>
#include <cstring>
int main()
{
	char s[300];
	int i,index;
	index=-4;
	scanf("%s",&s);
	for(i=0;i<(unsigned) strlen(s);i++)
	{
		if(s[i]=='W')
		{
			if(!(i<(unsigned) strlen(s)-2 && s[i+1]=='U' && s[i+2]=='B'))
			{
				printf("%c",s[i]);
				index=i;
			}
			else
			{
				if(index==i-1)
				{
					printf(" ");
				}
			}
		}
		else if(s[i]=='U')
		{
			if(!(i<(unsigned) strlen(s)-1 && i>0 && s[i+1]=='B' && s[i-1]=='W'))
			{
				printf("%c",s[i]);
				index=i;
			}
		}
		else if(s[i]=='B')
		{
			if(!(i>1 && s[i-1]=='U' && s[i-2]=='W'))
			{
				printf("%c",s[i]);
				index=i;
			}
		}
		else
		{
			printf("%c",s[i]);
			index=i;
		}
	}
	return 0;
}