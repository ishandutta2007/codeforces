#include <cstring>
#include <stdio.h>
char word[100000];
int main()
{
	int n,i,j,k;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	j=0;
	for(i=0;i<n;i++)
	{
		if(i-j>=2)
		{
			bool ok=false;
			for(k=i-2;k<=i;k++)
			{
				if(word[k]=='a' || word[k]=='e' || word[k]=='i' || word[k]=='o' || word[k]=='u')
					ok=true;
			}
			if(!(word[i-2]!=word[i-1] || word[i-1]!=word[i] || word[i-2]!=word[i])) ok=true;
			if(!ok)
			{
				printf(" ");
				j=i;
			}
		}
		printf("%c",word[i]);
	}
	return 0;
}