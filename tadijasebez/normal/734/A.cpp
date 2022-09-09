#include <stdio.h>
#include <cstring>
char word[100050];
int a,d;
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",&word);
	for(i=0;i<n;i++)
	{
		if(word[i]=='A') a++;
		else d++;
	}
	if(a>d) printf("Anton\n");
	if(d>a) printf("Danik\n");
	if(d==a) printf("Friendship\n");
	return 0;
}