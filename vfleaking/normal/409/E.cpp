#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	double x;
	cin >> x;
	
	for (int a = 1; a <= 10; a++)
		for (int h = 1; h <= 10; h++)
		{
			double y = 0.5 * a * h / sqrt(0.25 * a * a + h * h);
			if (floor(x * 1000000 + 0.5) == floor(y * 1000000 + 0.5))
			{
				cout << a << " " << h << endl;
				return 0;
			}
		}

	return 0;
}