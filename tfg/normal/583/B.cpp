#include <cstdio>

int a[1010];
bool gotten[1010];

int n;

int main()
{
	scanf("%i", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%i", a+i);
	}
	int inf=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i%2==0?0:n-1;i%2==0?(j<n):(j>=0);j+=i%2==0?1:-1)
		{
			if(a[j]<=inf && !gotten[j])
			{
				inf++;
				gotten[j]=true;
			}
		}
		if(inf==n)
		{
			printf("%i", i);
			return 0;
		}
	}
}