#include <cstdio>

int m=0, c=0;
int n;

int main()
{
	scanf("%i",&n);
	for(int i=0;i<n;i++)
	{
		int t1,t2;
		scanf("%i %i",&t1,&t2);
		if(t1>t2) m++;
		else if(t2>t1) c++;
	}
	if(m>c) printf("Mishka");
	else if(c>m) printf("Chris");
	else printf("Friendship is magic!^^");
}