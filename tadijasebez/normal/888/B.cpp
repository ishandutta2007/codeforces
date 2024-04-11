#include <stdio.h>
int min(int a, int b){ return a>b?b:a;}
char c[1000];
int l,r,u,d;
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",&c);
	for(i=0;i<n;i++)
	{
		if(c[i]=='L') l++;
		if(c[i]=='R') r++;
		if(c[i]=='U') u++;
		if(c[i]=='D') d++;
	}
	printf("%i\n",min(l,r)*2+min(u,d)*2);
	return 0;
}