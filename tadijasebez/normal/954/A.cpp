#include <stdio.h>
#include <cstring>
const int N=10000;
char s[N];
int main()
{
	int n,i,sol;
	scanf("%i",&n);
	scanf("%s",s+1);
	sol=n;
	for(i=1;i<=n;i++)
	{
		if(i<n && s[i]!=s[i+1]) sol--,i++;
	}
	printf("%i\n",sol);
	return 0;
}