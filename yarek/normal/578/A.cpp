#include <cstdio>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if(b > a)
	puts("-1");
    else if(b == a)
	printf("%d\n", b);
    else
    {
	double d = (a + b) / 2.0;
	int k = d / b;
	printf("%.10lf\n", d / k);
    }
}