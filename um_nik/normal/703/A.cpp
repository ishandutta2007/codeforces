#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	int bal = 0;
	scanf("%d", &n);
	while(n--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > y)
			bal++;
		if (x < y)
			bal--;
	}
	if (bal > 0)
		printf("Mishka\n");
	if (bal < 0)
		printf("Chris\n");
	if (bal == 0)
		printf("Friendship is magic!^^\n");

	return 0;
}