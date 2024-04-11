#include <iostream>
#include <cstdio>
using namespace std;
int x, y, z, t1, t2, t3;
int ABS(int x)
{
	return x >= 0 ? x : -x;
}
int main()
{
	scanf("%d%d%d%d%d%d", &x, &y, &z, &t1, &t2, &t3);
	if(t1 * ABS(y - x) >= 3 * t3 + t2 * ABS(y - x) + t2 * ABS(z - x)) printf("YES");
	else printf("NO");
	return 0;
}