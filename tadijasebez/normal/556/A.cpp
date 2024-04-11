#include <stdio.h>
const int N=200050;
char s[N];
int S[N],c;
int main()
{
	int n,i;
	scanf("%i %s",&n,s+1);
	for(i=1;i<=n;i++)
	{
		if(c && s[S[c]]!=s[i]) c--;
		else S[++c]=i;
	}
	printf("%i\n",c);
	return 0;
}