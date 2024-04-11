#include <bits/stdc++.h>
using namespace std;

int n, a;
int main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &a);
		if (a <= 1399) puts("Division 4");
		else if (a <= 1599) puts("Division 3");
		else if (a <= 1899) puts("Division 2");
		else puts("Division 1");
	}
	return 0;
}