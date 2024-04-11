#include<cstdio>
#include<algorithm>
using namespace std;

int x, y;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		if(a==25) x++;
		if(a==50)
		{
			if(x==0)
			{
				printf("NO\n");
				return 0;
			}
			y++;
			x--;
		}
		if(a==100)
		{
			if(y==0 && x<3)
			{
				printf("NO\n");
				return 0;
			}
			if(x==0)
			{
				printf("NO\n");
				return 0;
			}
			if(y>0)
			{
				y--;
				x--;
			}
			else x-=3;
		}
	}
	printf("YES\n");
	return 0;
}