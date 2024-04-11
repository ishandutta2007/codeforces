#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 101010;
int a, b, c, d, f[MAXN];
int main()
{
	memset(f, 0, sizeof(f));
	scanf("%d%d%d%d", &a, &b, &c, &d);
	for(int i = b; i < MAXN; i += a)
		f[i] |= 1;
	for(int i = d; i < MAXN; i += c)
		f[i] |= 2;
	for(int i = 0; i < MAXN; i++)
		if(f[i] == 3)
		{
			printf("%d\n", i);
			return 0;
		}
	printf("-1\n");
	return 0;
}