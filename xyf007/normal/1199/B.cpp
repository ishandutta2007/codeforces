#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
double h, l;
int main()
{
	scanf("%lf%lf", &h, &l);
	printf("%.10lf", (l * l - h * h) / (2 * h));
	return 0;
}