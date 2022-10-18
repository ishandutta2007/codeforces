#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int tux;
	cin >> tux;

	int foo = 0;
	int bar = 0;
	int baz = 0;
	int quz = 1;
	while (tux--)
	{
		int pur;
		cin >> pur;
		foo += pur;
		bar++;
		if (max(foo * quz, bar * baz) == foo * quz)
		{
			baz = foo;
			quz = bar;
		}
	}
	printf("%.10lf\n", (double)baz / quz);
}