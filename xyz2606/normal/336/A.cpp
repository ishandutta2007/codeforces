#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int x, y, sigma, x1, x2, y1, y2;
int main()
{
	scanf("%d%d", &x, &y);
	sigma = abs(x) + abs(y);
	x1 = x < 0?-sigma:sigma;
	y1 = 0;
	x2 = 0;
	y2 = y < 0?-sigma:sigma;
	if(x1 > x2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	printf("%d %d %d %d\n", x1, y1, x2, y2);
	fclose(stdin);
	return 0;
}