#include <cstdio>

char color[4];
int n,m;

int main()
{
	scanf("%i %i",&n,&m);
	for(int i=0;i<n*m;i++)
	{
		scanf(" %s",color);
		if(color[0]!='B' && color[0]!='W' && color[0]!='G')
		{
			printf("#Color");
			return 0;
		}
	}
	printf("#Black&White");
}