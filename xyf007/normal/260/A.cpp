#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a,b,n;
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&a,&b,&n);
	bool f=0;
	for (int i = 0; i < 10; ++i)
	{
		if ((a*10+i)%b==0)
		{
			printf("%d", a*10+i);
			for (int j = 1; j < n; ++j)
			{
				printf("0");
			}
			return 0;
		}
	}
	printf("-1");
	return 0;
}