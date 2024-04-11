#include <cstdio>
#include <algorithm>

int n, a[500];

int main()
{
	scanf("%i", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%i", a+i);
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				std::swap(a[j], a[j+1]);
				printf("%i %i\n",j+1,j+2);
			}
		}
	}
}