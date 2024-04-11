#include <stdio.h>
const int N=1050;
//#define ll long long
int main()
{
	int n,s,d;
	int sol=0;
	scanf("%i",&n);
	while(n --> 0)
	{
		scanf("%i %i",&s,&d);
		int prev=sol;
		//if(sol==s) sol+=d;
		while(sol<s) sol++;
		while((sol-s)%d!=0) sol++;
		if(sol==prev) sol++;
		while((sol-s)%d!=0) sol++;
	}
	printf("%i\n",sol);
	return 0;
}