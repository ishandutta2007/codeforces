#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int foo = 0, bar = 0, baz = 0, quz = 0;
	for (int i = 0; i < n; i++)
	{
		int pur;
		cin >> pur;
		foo += pur;
		bar++;
		if (foo * quz >= bar * baz)
		{
			baz = foo;
			quz = bar;
		}
	}
	cout << (double)baz / (double)quz;
	return 0;
}