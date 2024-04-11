#include <iostream>
#include <cstdio>
using namespace std;
int n, q;
int main()
{
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d", &n);
		if(n < 4 || n == 5 || n == 7 || n == 11)
		{
			printf("-1\n");
			continue;
		}
		int cnt = n / 4;
		if(n % 4 == 1) cnt--;
		if(n % 4 == 3) cnt--;
		printf("%d\n", cnt); 
	}
	return 0;
}