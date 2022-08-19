#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int a[4];

int main()
{
	for (int i = 0; i < 3; i++)
		scanf("%d", &a[i]);
	sort(a, a + 3);
	printf("%d\n", a[2] - a[0]);

	return 0;
}