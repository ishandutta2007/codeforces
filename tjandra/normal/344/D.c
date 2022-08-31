#include<stdio.h>
typedef unsigned u;
char S[100000];
int main()
{
	char c;
	u l=0;
	while((c=getchar())!='\n')
	{
		if(c=='+')S[l]='+';
		else if(c=='-')S[l]='-';
		else continue;
		if(l&&S[l]==S[l-1])l--;
		else l++;
	}
	if(l)printf("No\n");
	else printf("Yes\n");
	return 0;
}