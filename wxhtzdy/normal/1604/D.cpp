#include <bits/stdc++.h>
using namespace std;

int T,X,Y;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&X,&Y);
		if(X<Y)
		{
			int zz=Y/X;
			printf("%d\n",X*zz+(Y%(X*zz))/2);
		}
		else
		{
			if(X==Y)
			{
				printf("%d\n",X);
			}
			else
			{
				printf("%d\n",X+Y);
			}
		}
	}
	return 0;
}