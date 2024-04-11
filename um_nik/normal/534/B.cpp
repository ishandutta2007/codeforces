#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 110;
int t;
int x, y;
int a[N], b[N];
int s;
int d;

int main()
{
	scanf("%d%d", &x, &y);
	scanf("%d%d", &t, &d);
	for (int i = 0; i < t; i++)
		a[i] = x + i * d;
	for (int i = 0; i < t; i++)
		b[t - 1 - i] = y + i * d;
	s = 0;
	for (int i = 0; i < t; i++)
		s += min(a[i], b[i]);
	printf("%d\n", s);

	return 0;
}