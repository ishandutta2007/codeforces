#include <cstdio>

bool fixed[2][100];

int main()
{
	int n;
	scanf("%i", &n);
	for(int i=0;i<n*n;i++)
	{
		int x,y;
		scanf("%i %i", &x, &y);
		if(!fixed[0][x] && !fixed[1][y])
		{
			printf("%i ", i+1);
			fixed[0][x]=fixed[1][y]=true;
		}
	}
}