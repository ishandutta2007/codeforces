#include <iostream>
#include <cstdio>
using namespace std;
int n, ax, ay, bx, by, cx, cy;
int main()
{
	scanf("%d%d%d%d%d%d%d", &n, &bx, &by, &ax, &ay, &cx, &cy);
	int type1 = 0, type2 = 0;
	if(ax < bx) type1 += 1;
	else type1 += 2;
	if(ay < by) type1 += 4;
	else type1 += 8;
	if(cx < bx) type2 += 1;
	else type2 += 2;
	if(cy < by) type2 += 4;
	else type2 += 8;
	if(type1 == type2) printf("YES");
	else printf("NO");
	return 0;
}