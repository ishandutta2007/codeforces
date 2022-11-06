#include<stdio.h>
char s[100100];
int main()
{
	int n;
	scanf("%s", s);
	for(n=0; s[n] && s[n] == 'a'; n++);
	if(s[n] == 0)
	{
		s[n-1] = 'z';
		printf("%s", s);
		return 0;
	}
	for(; s[n] && s[n] != 'a'; n++)
	{
		s[n]--;
	}
	printf("%s", s);
	return 0;
}